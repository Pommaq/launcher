//
// Created by timmy on 10/25/20.
//

#ifndef UNTITLED_PROGRAM_H
#define UNTITLED_PROGRAM_H

#include <string>


class program {

    private:
        std::string p_path;
        std::string p_name;

    public:
        program() = delete;
        program(std::string& name, std::string& path);
        program(std::string &&name, std::string &&path) noexcept;
        void exec() const;
        program(program& other);
        program& operator=(program& other);
        program(program&& other) noexcept;
        program& operator=(program&& other) noexcept;
        ~program();

        std::string getname() const;
        std::string getpath() const;

};


#endif //UNTITLED_PROGRAM_H
