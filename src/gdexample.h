#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDExample : public Sprite2D {
    GDCLASS(GDExample, Sprite2D)

private:
    double time_passed;
    double amplitude_x;
    double amplitude_y;
    double speed;
    double time_emit;

protected:
    static void _bind_methods();

public:
    GDExample();
    ~GDExample();

    void set_amplitude_x(const double p_amplitude);
    double get_amplitude_x() const;
    void set_amplitude_y(const double p_amplitude);
    double get_amplitude_y() const;
    void set_speed(const double p_speed);
    double get_speed() const;

    void _init();
    void  _process(double delta);
};

}

#endif
