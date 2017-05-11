#ifndef VIDEO_H
#define VIDEO_H

namespace kernel
{
	namespace Text
	{
		// Konstruktor
		void init();
		
		// Leeren des Bildschirms, die Gr��e betr�gt 80x25 Zeichen
		void clear();

		// Textausgabe
		void printf(const char* s);

		// Vordergrundfarbe setzen
		void ForegroundColor (Color color);

		// Hintergrundfarbe setzen
		void BackgroundColor (Color color);

		// Ausgabe eines einzelnen Zeichens
		void putc(char cC);
		
		void Scroll();
	}
}
#endif