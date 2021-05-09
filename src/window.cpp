#include "pch.h"
#include "window.h"
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
namespace gifgenerator {
    window::window(int32_t major, int32_t minor) {
        this->m_window_data = { major, minor, NULL };
        this->init_window();
    }
    window::~window() {
        this->destroy_window();
    }
    bool window::initialized() {
        return this->m_window_data.window != NULL;
    }
    bool window::should_close() {
        return glfwWindowShouldClose(this->m_window_data.window);
    }
    void window::new_frame() {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }
    void window::render_imgui() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(this->m_window_data.window);
    }
    void window::init_window() {
        if (!glfwInit()) return;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, this->m_window_data.context_major_version);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, this->m_window_data.context_minor_version);
        this->m_window_data.window = glfwCreateWindow(800, 600, "gif-generator", NULL, NULL);
        glfwMakeContextCurrent(this->m_window_data.window);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(this->m_window_data.window, true);
        std::stringstream shaderversion;
        shaderversion << "#version " << std::to_string(this->m_window_data.context_major_version) << std::to_string(this->m_window_data.context_minor_version) << "0";
        std::string version = shaderversion.str();
        ImGui_ImplOpenGL3_Init(version.c_str());
    }
    void window::destroy_window() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwDestroyWindow(this->m_window_data.window);
        glfwTerminate();
    }
}