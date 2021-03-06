#ifndef _LED_STRIP_H_
#define _LED_STRIP_H_

#include "FastLED/FastLED.h"
#include "Color_Container.h"
#include "Pin_Defs.h"


/**	Enum direction that is used to determine if the strip chase animation runs 'forward' or 'backward' */

enum direction {

	forward,	/**< With direction of power/signal flow */
	backward	/**< Against direction of power/signal flow */

};


/**	Class LEDStrip that is used to represent a NeoPixel LED strip
	@extends CFastLED */

class LEDStrip : public CFastLED {

	int pixelCount;									/**< Number of pixels in strip - set in constructor */
	CRGB * ledArray;									/**< Pointer to the array of structures holding the pixel values */

public:

	LEDStrip( int numLEDs, int pin );
	LEDStrip( const LEDStrip& );
	~LEDStrip() {};
																							// TODO: Add Copy Constructor and Destructor

	void
		setPixelColor( int pixel, ColorContainer colorValues ),	// Sets the color of one pixel to the color stored in a ColorContainer object
		setPixelColor( int pixel, int rIn, int gIn, int bIn ),	// Calls setPixelColor(int, ColorContainer) with a ColorContainer created from the inputted rgb values
		setStripColor( ColorContainer colorValues ),	// Sets the color of the whole strip to the color stored in a ColorContainer object
		setStripColor( int rIn, int gIn, int bIn ),	// Calls setStripColor(ColorContainer) with a ColorContainer created from the inputted rgb values
		fillLEDsFromPalette( const TProgmemRGBPalette16& palette, uint8_t startIndex, TBlendType blend, uint8_t brightness );	// Fills a LED strip with the colors from a FastLED Color Palette -- based on FastLED example code
	
	template <class paletteType> void fillLEDsFromPalette( const paletteType& palette, uint8_t startIndex, TBlendType blend, uint8_t brightness );

																							// Also look through the FastLED library to see what else is possible

	int
		getPixelCount(),	// Returns pixelCount
		getPixelRed( int pixelIn ),	// Returns intensity of red in the specified pixel
		getPixelGreen( int pixelIn ),	// Returns intensity of green in the specified pixel
		getPixelBlue( int pixelIn );	// Returns intensity of blue in the specified pixel

	ColorContainer
		getPixelColor( int );	// Returns a ColorContainer with the red, green and blue intensities of the pixel

	CRGB * getLEDArray() { return ledArray; }

													// TODO: Add assignment operator method
	CRGB & operator[]( int indexIn ) { return ledArray[indexIn]; }	// Index Operator method

};


#endif  // _LED_STRIP_H_