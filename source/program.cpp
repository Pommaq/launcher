//
// Created by timmy on 10/25/20.
//

#include <string>
#include <iostream>
#include "../includes/program.h"


program::program(std::string& name, std::string& path) {
    this->p_name = name;
    this->p_path = path;
}

program::program(std::string &&name, std::string &&path) noexcept {
    this->p_path = std::move(path);
    this->p_name = std::move(name);
}

void program::exec() const {
//TODO write this
    std::cout << "stub" << std::endl;
}

program::program(program &other) {
    this->p_path = other.p_path;
    this->p_name = other.p_name;
}

program &program::operator=(program &other) {
    this->p_path = other.p_path;
    this->p_name = other.p_name;

    return *this;
}

program::program(program &&other) noexcept {
    this->p_name = std::move(other.p_name);
    this->p_path = std::move(other.p_path);
}

program &program::operator=(program &&other) noexcept {
    this->p_path = std::move(other.p_path);
    this->p_name = std::move(other.p_name);

    return *this;
}

program::~program() {

    return;
}

std::string program::getname() const {
    return this->p_name;
}

std::string program::getpath() const {
    return this->p_path;
}
