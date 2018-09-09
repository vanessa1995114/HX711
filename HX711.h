#ifndef HX711_h
#define HX711_h
#define pulse(pin) { digitalWrite(pin, HIGH); digitalWrite(pin, LOW); }
#include "Arduino.h"


class HX711
{
	private:
		byte SCK;	// Serial Clock Input Pin
		byte DOUT;		// Serial Data Output Pin
		byte AMP;		// amplification factor
		long OFFSET;	// used for tare weight
		double COEFFICIENT;
	
	public:
	
		HX711(byte sck, byte dout, byte amp = 128, double co = 1);   // define SCK and dout pin, amplification factor and coefficient 
		void set_amp(byte amp);   // set amplification factor, take effect after one call to read()
		bool is_ready();  // test hx711 is ready or not, will be called in read()
		long read();  // return difference votage, will be blocked if hx711 is not ready
		double bias_read();  // return (read() - offset) * coefficient
		void tare(int t = 10);  //set no-load value to offset, equal to average of t times read();
		void set_co(double co = 1);  //	set coefficient
		void set_offset(long offset = 0);  // set offset
};
#endif
