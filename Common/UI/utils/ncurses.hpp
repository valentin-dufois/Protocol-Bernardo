//
//  ncurses.hpp
//  Music Composer
//
//  Created by Valentin Dufois on 24/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef ncurses_hpp
#define ncurses_hpp

#include <iostream>

// NCURSES
#define _XOPEN_SOURCE_EXTENDED // UTF-8
#include "ncurses.h"

#include "../UI.hpp"

namespace ui {

using nCursesVoidElement = unsigned short int;

//Very ugly wrapper for the nCurses library
class nCurses
{
public:
	/**
	 Init the nCurses library
	 */
	static void init();

	/**
	 Move the cursor on the terminal to the desired location

	 @param col x/col position
	 @param row y/row position
	 */
	static nCursesVoidElement move(int col, int row);
	inline static nCursesVoidElement mv(int col, int row) { return move(col, row); };

//PRINTERS

	struct Print
	{
		/**
		 Print a string on the screen

		 @param toPrint What to print
		 @return The stream
		 */
		Print & operator<< (const std::string &toPrint)
		{
			printw(toPrint.c_str());
			return * this;
		}

		/**
		 Print an int on the screen

		 @param toPrint What to print
		 @return The stream
		 */
		Print & operator<< (const int &toPrint)
		{
			printw("%d", toPrint);
			return * this;
		}

		/**
		 Print a char on the screen

		 @param toPrint What to print
		 @return The stream
		 */
		Print & operator<< (const char &toPrint)
		{
			printw("%c", toPrint);
			return * this;
		}

        /**
         Print a wide char on the screen

         @param toPrint What to print
         @return The stream
         */
        Print & operator<< (const char toPrint[])
        {
            addstr(toPrint);
            return * this;
        }

		/**
		 Print a nCurses char on the screen

		 @param toPrint What to print
		 @return The stream
		 */
		Print & operator<< (const chtype &toPrint)
		{
			addch(toPrint);
			return * this;
		}

		/**
		 handles printing modifiers

		 @param nullElement a null element (unsigned short int)
		 @return The stream
		 */
		Print & operator<< (const nCursesVoidElement &) {
			return * this;
		};
	};

	static Print print;

	/**
	 Print a graphical string on the screen
	 This function automatically replace the following characters with proper drawing char :
	 	| - ┐ └ ├ ┤ ┬ ┴ ┘ ┌

	 @param col X position
	 @param row Y position
	 @param toPrint What to print
	 */
	static void printGraphic(const int &col, const int &row, const std::u32string &toPrint);

//STYLING

	/**
	 Erase screen and revert all texts and colors styling
	 */
	static void clear();

	/**
	 Revert all texts and colors styling
	 */
	static void clearStyling();

	/**
	 Replace all the characters in the given area by a fast, effectevly clearing them
	 */
    static void clearArea(const int &col, const int &row, const uint &width, const uint &height);

	/**
	 Erase window content ; replace every char by a space (relatively fast)
	 */
	inline static void clearWindow() {
		clearArea(0, 0, getWindowWidth(), getWindowHeight());
	};

	/**
	 Revert to default text
	 */
	static void setDefaultStyle();

	/**
	 Revert to default colors
	 */
	static void setDefaultColors();


	/**
	 Set text to bold
	 */
	static nCursesVoidElement setBold();

	/**
	 Remove bold attribute
	 */
	static nCursesVoidElement removeBold();

	/**
	 Set text to blink
	 */
	static nCursesVoidElement setBlink();

	/**
	 Remove blink attribute
	 */
	static nCursesVoidElement removeBlink();

	/**
	 Add underline to the text
	 */
	static nCursesVoidElement setUnderline();

	/**
	 Remove underline
	 */
	static nCursesVoidElement removeUnderline();

	/**
	 Set text color

	 @param nCursesColor An nCurses color macro
	 */
	static void setForeground(int nCursesColor);

	/**
	 Set background color

	 @param nCursesColor An nCurses color macro
	 */
	static void setBackground(int nCursesColor);


	/**
	 Set text and background color

	 @param foregroundColor An nCurses color macro for the text
	 @param backgroundColor An nCurses color macro for the background
	 */
	static void setColors(int foregroundColor, int backgroundColor);

//DRAWING (KIND OF)

	/**
	 Draw a box on the screen

	 @param col Top left corner X position
	 @param row Top left corner Y position
	 @param width Width of the box
	 @param height Height of the box
	 */
	static void box(const int &col, const int &row, const uint &width, const uint &height);

	/**
	 Draw a horizontal line

	 @param col X position of the left extremity
	 @param row Y position of the left extremity
	 @param length Length of the line
	 */
	static void hLine(const int &col, const int &row, const uint &length);

	/**
	 Draw a vertical line on the screen

	 @param col X position of the top extremity
	 @param row Y position of the top extremity
	 @param length Length of the line
	 */
	static void vLine(const int &col, const int &row, const uint &length);


//WINDOW PROPERTIES

	/**
	 @return Number of columns (width)
	 */
	inline static uint getWindowWidth() { return COLS; };


	/**
	 @return Number of rows (height)
	 */
	inline static uint getWindowHeight() { return LINES; };

	/**
	 Erase window content (slow)
	 */
    inline static void rawClear() { ::clear(); };

	/**
	 Get left position of an object centered on screen

	 @param width Object width
	 @return The left position
	 */
	inline static int HCenterOffset(const uint &width) { return (getWindowWidth() - width) / 2; };

	/**
	 Get the top position of an object centered on screen

	 @param height Object height
	 @return The top position
	 */
	inline static int VCenterOffset(const uint &height) { return (getWindowHeight() - height) / 2; };

private:
	static int m_currentForeground;
	static int m_currentBackground;
	static int m_lastColorID;

	/**
	 Will update the screen printing colors based on the current ones
	 */
	static void updateColors();
};

//Shorthand for nCurses calls
using nC = nCurses;

} /* ::ui */

#endif /* ncurses_hpp */
