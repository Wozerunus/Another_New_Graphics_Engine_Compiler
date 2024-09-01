// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
  int null = 0;
  int rectangle_id = 1, triangle_id = 2, circle_id = 3;
  int image_id = 4, text_id = 5;
  int rectangle_x, rectangle_y, rectangle_w, rectangle_h;
  int triangle_x1, triangle_x2,
        triangle_y1, triangle_y2,
        triangle_z1, triangle_z2;
  int circle_x, circle_y, circle_rad;
  int image_x, image_y, image_w, image_h;
  char image_path[64];
  int text_x, text_y, text_size;
  wchar_t text_msg[64];
  char text_font[64];
  int symbol_count;
  int r, g, b, a;

  setlocale(0, "ru");
  std::locale::global(std::locale("Russian_Russia"));
  std::string input_file_name, output_file_name;
  std::cout << "Введите имя входного файла: ";
  std::cin >> input_file_name;
  std::cout << "Введите имя выходного файла: ";
  std::cin >> output_file_name;

  std::ifstream in {input_file_name};
  std::ofstream out {output_file_name, std::ios::binary};
  std::vector<std::vector<std::string>> result;

  std::string value, text;
  while (!in.eof()) {
    value = text = "";
    std::vector<std::string> line;
    while (value != ";") {
      if (value == "\n") {
        in >> value;
      } else if (value == "\"") {
        value = "";
        while (value != "\"") {
          in >> value;
          if (value != "\"") {
            text += value += " ";
          }
        }
        line.push_back(text);
        value = "";
      } else {
        in >> value;
        if (value != ";" && value != "\"") {
          line.push_back(value);
        }
      }
    }
    result.push_back(line);
  }
  in.close();
  out.clear();

  for (auto iter{result.begin()}; iter != result.end(); ++iter) {
    switch (std::stoi((*iter)[0])) {
      case 1:
        rectangle_x = std::stoi((*iter)[1]);
        rectangle_y = std::stoi((*iter)[2]);
        rectangle_w = std::stoi((*iter)[3]);
        rectangle_h = std::stoi((*iter)[4]);
        r = std::stoi((*iter)[5]);
        g = std::stoi((*iter)[6]);
        b = std::stoi((*iter)[7]);
        a = std::stoi((*iter)[8]);
        out.write(reinterpret_cast<char*>(&rectangle_id), sizeof(rectangle_id));
        out.write(reinterpret_cast<char*>(&rectangle_x),  sizeof(rectangle_x));
        out.write(reinterpret_cast<char*>(&rectangle_y),  sizeof(rectangle_y));
        out.write(reinterpret_cast<char*>(&rectangle_w),  sizeof(rectangle_w));
        out.write(reinterpret_cast<char*>(&rectangle_h),  sizeof(rectangle_h));
        out.write(reinterpret_cast<char*>(&r),            sizeof(r));
        out.write(reinterpret_cast<char*>(&g),            sizeof(g));
        out.write(reinterpret_cast<char*>(&b),            sizeof(b));
        out.write(reinterpret_cast<char*>(&a),            sizeof(a));
        break;
      case 2:
        triangle_x1 = std::stoi((*iter)[1]);
        triangle_x2 = std::stoi((*iter)[2]);
        triangle_y1 = std::stoi((*iter)[3]);
        triangle_y2 = std::stoi((*iter)[4]);
        triangle_z1 = std::stoi((*iter)[5]);
        triangle_z2 = std::stoi((*iter)[6]);
        r = std::stoi((*iter)[7]);
        g = std::stoi((*iter)[8]);
        b = std::stoi((*iter)[9]);
        a = std::stoi((*iter)[10]);
        out.write(reinterpret_cast<char*>(&triangle_id), sizeof(triangle_id));
        out.write(reinterpret_cast<char*>(&triangle_x1), sizeof(triangle_x1));
        out.write(reinterpret_cast<char*>(&triangle_x2), sizeof(triangle_x2));
        out.write(reinterpret_cast<char*>(&triangle_y1), sizeof(triangle_y1));
        out.write(reinterpret_cast<char*>(&triangle_y2), sizeof(triangle_y2));
        out.write(reinterpret_cast<char*>(&triangle_z1), sizeof(triangle_z1));
        out.write(reinterpret_cast<char*>(&triangle_z2), sizeof(triangle_z2));
        out.write(reinterpret_cast<char*>(&r),           sizeof(r));
        out.write(reinterpret_cast<char*>(&g),           sizeof(g));
        out.write(reinterpret_cast<char*>(&b),           sizeof(b));
        out.write(reinterpret_cast<char*>(&a),           sizeof(a));
        break;
      case 3:
        circle_x = std::stoi((*iter)[1]);
        circle_y = std::stoi((*iter)[2]);
        circle_rad = std::stoi((*iter)[3]);
        r = std::stoi((*iter)[4]);
        g = std::stoi((*iter)[5]);
        b = std::stoi((*iter)[6]);
        a = std::stoi((*iter)[7]);
        out.write(reinterpret_cast<char*>(&circle_id),     sizeof(circle_id));
        out.write(reinterpret_cast<char*>(&circle_x),      sizeof(circle_x));
        out.write(reinterpret_cast<char*>(&circle_y),      sizeof(circle_y));
        out.write(reinterpret_cast<char*>(&circle_rad),    sizeof(circle_rad));
        out.write(reinterpret_cast<char*>(&r),             sizeof(r));
        out.write(reinterpret_cast<char*>(&g),             sizeof(g));
        out.write(reinterpret_cast<char*>(&b),             sizeof(b));
        out.write(reinterpret_cast<char*>(&a),             sizeof(a));
        break;
      case 4:
        image_x = std::stoi((*iter)[1]);
        image_y = std::stoi((*iter)[2]);
        image_w = std::stoi((*iter)[3]);
        image_h = std::stoi((*iter)[4]);
        strcpy(image_path, (*iter)[5].c_str());
        out.write(reinterpret_cast<char*>(&image_id),   sizeof(image_id));
        out.write(reinterpret_cast<char*>(&image_x),    sizeof(image_x));
        out.write(reinterpret_cast<char*>(&image_y),    sizeof(image_y));
        out.write(reinterpret_cast<char*>(&image_w),    sizeof(image_w));
        out.write(reinterpret_cast<char*>(&image_h),    sizeof(image_h));
        out.write(reinterpret_cast<char*>(&image_path), 64);
        break;
      case 5:
        text_x = std::stoi((*iter)[1]);
        text_y = std::stoi((*iter)[2]);
        for (size_t i = 0; i < 63; i++) {
          text_msg[i] = ' ';
        }
        symbol_count = std::stoi((*iter)[3]);
        mbstowcs(text_msg, (*iter)[4].c_str(), (*iter)[4].size());
        strcpy(text_font, (*iter)[5].c_str());
        text_size = std::stoi((*iter)[6]);
        r = std::stoi((*iter)[7]);
        g = std::stoi((*iter)[8]);
        b = std::stoi((*iter)[9]);
        a = std::stoi((*iter)[10]);
        out.write(reinterpret_cast<char*>(&text_id),      sizeof(text_id));
        out.write(reinterpret_cast<char*>(&text_x),       sizeof(text_x));
        out.write(reinterpret_cast<char*>(&text_y),       sizeof(text_y));
        out.write(reinterpret_cast<char*>(&symbol_count), sizeof(symbol_count));
        out.write(reinterpret_cast<char*>(&text_msg),     64);
        out.write(reinterpret_cast<char*>(&text_font),    64);
        out.write(reinterpret_cast<char*>(&text_size),    sizeof(text_size));
        out.write(reinterpret_cast<char*>(&r),            sizeof(r));
        out.write(reinterpret_cast<char*>(&g),            sizeof(g));
        out.write(reinterpret_cast<char*>(&b),            sizeof(b));
        out.write(reinterpret_cast<char*>(&a),            sizeof(a));
        break;
      default:
        break;
    }
  }
  out.write(reinterpret_cast<char*>(&null), sizeof(null));
  out.close();

  return EXIT_SUCCESS;
}
