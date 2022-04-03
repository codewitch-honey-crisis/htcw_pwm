#pragma once
#include <Arduino.h>
#include <gfx_core.hpp>
#include <gfx_pixel.hpp>
#include <gfx_positioning.hpp>
namespace arduino {
    // controls up to 16 PWM channels, presenting a draw target with a width of N channels, each a grayscale pixel of BitDepth
    template<uint32_t FrequencyHz=5000, 
            uint8_t BitDepth=8, 
            int8_t PinPwm1=-1,
            int8_t PinPwm2=-1,
            int8_t PinPwm3=-1,
            int8_t PinPwm4=-1,
            int8_t PinPwm5=-1,
            int8_t PinPwm6=-1,
            int8_t PinPwm7=-1,
            int8_t PinPwm8=-1,
            int8_t PinPwm9=-1,
            int8_t PinPwm10=-1,
            int8_t PinPwm11=-1,
            int8_t PinPwm12=-1,
            int8_t PinPwm13=-1,
            int8_t PinPwm14=-1,
            int8_t PinPwm15=-1,
            int8_t PinPwm16=-1>
    struct pwm {
        constexpr static const uint32_t frequency_hz = FrequencyHz;
        constexpr static const uint8_t bit_depth = BitDepth;
        constexpr static const int8_t pin_pwm1 = PinPwm1;
        constexpr static const int8_t pin_pwm2 = PinPwm2;
        constexpr static const int8_t pin_pwm3 = PinPwm3;
        constexpr static const int8_t pin_pwm4 = PinPwm4;
        constexpr static const int8_t pin_pwm5 = PinPwm5;
        constexpr static const int8_t pin_pwm6 = PinPwm6;
        constexpr static const int8_t pin_pwm7 = PinPwm7;
        constexpr static const int8_t pin_pwm8 = PinPwm8;
        constexpr static const int8_t pin_pwm9 = PinPwm9;
        constexpr static const int8_t pin_pwm10 = PinPwm10;
        constexpr static const int8_t pin_pwm11 = PinPwm11;
        constexpr static const int8_t pin_pwm12 = PinPwm12;
        constexpr static const int8_t pin_pwm13 = PinPwm13;
        constexpr static const int8_t pin_pwm14 = PinPwm14;
        constexpr static const int8_t pin_pwm15 = PinPwm15;
        constexpr static const int8_t pin_pwm16 = PinPwm16;
        constexpr static const uint16_t width = uint16_t((PinPwm1!=-1)+(PinPwm2!=-1)+(PinPwm3!=-1)+(PinPwm4!=-1)+(PinPwm5!=-1)+(PinPwm6!=-1)+(PinPwm7!=-1)+(PinPwm8!=-1)+(PinPwm9!=-1)+(PinPwm10!=-1)+(PinPwm11!=-1)+(PinPwm12!=-1)+(PinPwm13!=-1)+(PinPwm14!=-1)+(PinPwm15!=-1)+(PinPwm16!=-1));
        constexpr static const uint16_t height = 1;
        static_assert(PinPwm1!=-1||PinPwm2!=-1||PinPwm3!=-1||PinPwm4!=-1||PinPwm5!=-1||PinPwm6!=-1||PinPwm7!=-1||PinPwm8!=-1||PinPwm9!=-1||PinPwm10!=-1||PinPwm11!=-1||PinPwm12!=-1||PinPwm13!=-1||PinPwm14!=-1||PinPwm15!=-1||PinPwm16!=-1,"A pin for at least one PWM channel must be specified.");
        using pixel_type = gfx::gsc_pixel<bit_depth>;
        using caps = gfx::gfx_caps<false,false,false,false,false,true,false>;
    private:
        bool m_initialized;
        static constexpr int8_t x_to_channel(int x) {
            if(x<0) return -1;
            int i=-1;
            if(pin_pwm1!=-1) ++i;
            if(i==x) return 0;
            if(pin_pwm2!=-1) ++i;
            if(i==x) return 1;
            if(pin_pwm3!=-1) ++i;
            if(i==x) return 2;
            if(pin_pwm4!=-1) ++i;
            if(i==x) return 3;
            if(pin_pwm5!=-1) ++i;
            if(i==x) return 4;
            if(pin_pwm6!=-1) ++i;
            if(i==x) return 5;
            if(pin_pwm7!=-1) ++i;
            if(i==x) return 6;
            if(pin_pwm8!=-1) ++i;
            if(i==x) return 7;
            if(pin_pwm9!=-1) ++i;
            if(i==x) return 8;
            if(pin_pwm10!=-1) ++i;
            if(i==x) return 9;
            if(pin_pwm11!=-1) ++i;
            if(i==x) return 10;
            if(pin_pwm12!=-1) ++i;
            if(i==x) return 11;
            if(pin_pwm13!=-1) ++i;
            if(i==x) return 12;
            if(pin_pwm14!=-1) ++i;
            if(i==x) return 13;
            if(pin_pwm15!=-1) ++i;
            if(i==x) return 14;
            if(pin_pwm16!=-1) ++i;
            if(i==x) return 15;
            return -1;
        }
    public:
        pwm() : m_initialized(false) {

        }
        gfx::gfx_result initialize() {
            if(!m_initialized) {
                if(pin_pwm1!=-1) {
                    ledcSetup(0,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm1,0);
                }
                if(pin_pwm2!=-1) {
                    ledcSetup(1,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm2,1);
                }
                if(pin_pwm3!=-1) {
                    ledcSetup(2,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm3,2);
                }
                if(pin_pwm4!=-1) {
                    ledcSetup(3,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm4,3);
                }
                if(pin_pwm5!=-1) {
                    ledcSetup(4,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm5,4);
                }
                if(pin_pwm6!=-1) {
                    ledcSetup(5,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm6,5);
                }
                if(pin_pwm7!=-1) {
                    ledcSetup(6,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm7,6);
                }
                if(pin_pwm8!=-1) {
                    ledcSetup(7,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm8,7);
                }
                if(pin_pwm9!=-1) {
                    ledcSetup(8,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm9,8);
                }
                if(pin_pwm10!=-1) {
                    ledcSetup(9,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm10,9);
                }
                if(pin_pwm11!=-1) {
                    ledcSetup(10,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm11,10);
                }
                if(pin_pwm12!=-1) {
                    ledcSetup(11,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm12,11);
                }
                if(pin_pwm13!=-1) {
                    ledcSetup(12,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm13,12);
                }
                if(pin_pwm14!=-1) {
                    ledcSetup(13,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm14,13);
                }
                if(pin_pwm15!=-1) {
                    ledcSetup(14,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm15,14);
                }
                if(pin_pwm16!=-1) {
                    ledcSetup(15,frequency_hz,bit_depth);
                    ledcAttachPin((uint8_t)pin_pwm16,15);
                }
                m_initialized=true;
            }
            return gfx::gfx_result::success;
        }
        
        inline bool initialized() const { return m_initialized; }
        inline gfx::size16 dimensions() const { return {width,height}; };
        inline gfx::rect16 bounds() const { return dimensions().bounds(); }
        inline gfx::gfx_result point(gfx::point16 location, pixel_type color) {
            gfx::gfx_result r = initialize();
            if(r!=gfx::gfx_result::success) {
                return r;
            }
            if(location.y<0 || location.y>=height) {
                return gfx::gfx_result::success;
            }
            int8_t ch = x_to_channel(location.x);
            if(ch!=-1) {
                ledcWrite((uint8_t)ch,color.template channel<0>());
            }
            return gfx::gfx_result::success;
        }
        gfx::gfx_result fill(const gfx::rect16& bounds,pixel_type color) {
            gfx::gfx_result r = initialize();
            if(r!=gfx::gfx_result::success) {
                return r;
            }
            const gfx::rect16 rr = bounds.crop(this->bounds()).normalize();
            for(int i = rr.x1;i<=rr.x2;++i) {
                int8_t ch = x_to_channel(i);
                if(ch!=-1) {
                    ledcWrite((uint8_t)ch,color.template channel<0>());
                }
            }
            return gfx::gfx_result::success;
        }
        inline gfx::gfx_result clear(const gfx::rect16& bounds) { 
            pixel_type px;
            return fill(bounds,px);
        }
        gfx::gfx_result point(gfx::point16 location,pixel_type* out_color) const {
            if(!initialized()) {
                return gfx::gfx_result::invalid_state;
            }
            if(location.y<0 || location.y>=height) {
                return gfx::gfx_result::success;
            }
            int8_t ch = x_to_channel(location.x);
            if(ch!=-1) {
                using t = typename pixel_type::int_type;
                out_color->template channel<0>((t)ledcRead(ch));
            }
            return gfx::gfx_result::success;
        }
    };
}