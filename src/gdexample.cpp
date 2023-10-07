#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_amplitude_x"), &GDExample::get_amplitude_x);
    ClassDB::bind_method(D_METHOD("set_amplitude_x","p_amplitude"), &GDExample::set_amplitude_x);
    ClassDB::add_property("GDExample", PropertyInfo(Variant::FLOAT, "amplitude_x"), "set_amplitude_x", "get_amplitude_x");

    ClassDB::bind_method(D_METHOD("get_amplitude_y"), &GDExample::get_amplitude_y);
    ClassDB::bind_method(D_METHOD("set_amplitude_y","p_amplitude"), &GDExample::set_amplitude_y);
    ClassDB::add_property("GDExample", PropertyInfo(Variant::FLOAT, "amplitude_y"), "set_amplitude_y", "get_amplitude_y");

    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &GDExample::set_speed);
    ClassDB::add_property("GDExample", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));
}

GDExample::GDExample() {
    time_passed = 0.0;
    amplitude_x = 10.0;
    amplitude_y = 10.0;
    speed = 1.0;
}

GDExample::~GDExample() {

}

void GDExample::_init() {
    time_emit = 0.0;
}

void GDExample::_process(double delta) {
    time_passed += delta * speed;

    Vector2 new_position = Vector2(
        amplitude_x + (amplitude_x * sin(time_passed * 2.0)),
        amplitude_y + (amplitude_y * cos(time_passed * 2.0))
    );

    set_position(new_position);

    time_emit += delta;
    if (time_emit >= 1.0) {
        emit_signal("position_changed", this, new_position);
        time_emit = 0.0;
    }
}

void GDExample::set_amplitude_x(const double p_amplitude) {
    amplitude_x = p_amplitude;
}

double GDExample::get_amplitude_x() const {
    return amplitude_x;
}

void GDExample::set_amplitude_y(const double p_amplitude) {
    amplitude_y = p_amplitude;
}

double GDExample::get_amplitude_y() const {
    return amplitude_y;
}

void GDExample::set_speed(const double p_speed) {
    speed = p_speed;
}

double GDExample::get_speed() const {
    return speed;
}

