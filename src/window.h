#pragma once
namespace gifgenerator {
    class window {
    public:
        window(int32_t major, int32_t minor);
        ~window();
        bool initialized();
        bool should_close();
        void new_frame();
        void render_imgui();
    private:
        void init_window();
        void destroy_window();
        struct {
            int32_t context_major_version, context_minor_version;
            GLFWwindow* window;
        } m_window_data;
    };
}