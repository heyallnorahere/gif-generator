#include "pch.h"
#include "panels.h"
namespace gifgenerator {
    static std::string parse_path(const std::string& path) {
        size_t pos = path.find_last_of('.');
        std::string without_ext;
        if (pos == std::string::npos) {
            without_ext = path;
        } else {
            without_ext = path.substr(0, pos);
        }
        return without_ext + ".gif";
    }
    void selection_panel() {
        ImGui::Begin("Select your JSON file");
        static std::string json_file_path;
        ImGui::InputText("File to parse", &json_file_path);
        if (ImGui::Button("Generate!")) {
            std::string gif_path = parse_path(json_file_path);
            // do something with those two paths; for now, lets just print them
            std::cout << "json: " << json_file_path << std::endl;
            std::cout << "gif: " << gif_path << std::endl;
            json_file_path.clear();
        }
        ImGui::End();
    }
}