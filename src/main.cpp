#include "pch.h"
#include "window.h"
int main(int argc, const char* argv[]) {
    auto window = std::make_shared<gifgenerator::window>(4, 1);
    while (!window->should_close()) {
        window->new_frame();
        {
            ImGui::Begin("test");
            ImGui::Text("test");
            ImGui::End();
        }
        window->render_imgui();
    }
    return 0;
}