#pragma once

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
extern "C"
{
#endif

  extern const int PicoKeypad__PadsNumber;
  void PicoKeypad__init();
  void PicoKeypad__set_brightness(float brightness);
  void PicoKeypad__illuminate(int i, unsigned char r, unsigned char g, unsigned char b);
  void PicoKeypad__update();
  uint16_t PicoKeypad__get_button_states();

#ifdef __cplusplus /* If this is a C++ compiler, end C linkage */
}
#endif
