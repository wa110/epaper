 //#define BYTES_PER_CHAR 44
 /*PROGMEM const prog_uint8_t font_bits[]  = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 001 ( )
   0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		 					// Char 002 (!)
   0x00, 0x00, 0x38, 0x07, 0x38, 0x07, 0x38, 0x07, 0x38, 0x07, 0x10, 0x02,
   0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 003 (")
   0x80, 0x08, 0x80, 0x08, 0x80, 0x08, 0x40, 0x04, 0x40, 0x04, 0x40, 0x04,
   0xf8, 0x3f, 0x40, 0x04, 0x40, 0x04, 0x40, 0x04, 0x40, 0x04, 0xf8, 0x3f,
   0x40, 0x04, 0x40, 0x04, 0x40, 0x04, 0x20, 0x02, 0x20, 0x02, 0x20, 0x02,
   0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 004 (#)
   0x80, 0x00, 0xe0, 0x01, 0x10, 0x0e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
   0x08, 0x00, 0x70, 0x00, 0x80, 0x07, 0x00, 0x08, 0x00, 0x10, 0x00, 0x10,
   0x04, 0x10, 0x04, 0x08, 0x1c, 0x0c, 0xf4, 0x03, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 005 ($)
   0xe0, 0x00, 0x10, 0x01, 0x08, 0x02, 0x08, 0x02, 0x08, 0x02, 0x10, 0x01,
   0xe0, 0x00, 0x00, 0x1c, 0xc0, 0x03, 0x38, 0x00, 0x00, 0x07, 0x80, 0x08,
   0x40, 0x10, 0x40, 0x10, 0x40, 0x10, 0x80, 0x08, 0x00, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 006 (%)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x40, 0x00, 0x20, 0x00,
   0x20, 0x00, 0x20, 0x00, 0x40, 0x00, 0x60, 0x00, 0x90, 0x18, 0x08, 0x09,
   0x08, 0x05, 0x08, 0x06, 0x18, 0x06, 0x10, 0x07, 0xe0, 0x19, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 007 (&)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,
   0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 008 (')
   0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x18, 0x00, 0x08, 0x00, 0x0c,
   0x00, 0x04, 0x00, 0x04, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02,
   0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x04, 0x00, 0x04,
   0x00, 0x0c, 0x00, 0x08, 0x00, 0x18, 0x00, 0x10,							// Char 009 (()
   0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x60, 0x00, 0x40, 0x00, 0xc0, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x80, 0x00, 0x80, 0x00,
   0xc0, 0x00, 0x40, 0x00, 0x60, 0x00, 0x20, 0x00,							// Char 010 ())
   0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
   0x30, 0x31, 0xc0, 0x0f, 0x00, 0x03, 0x00, 0x03, 0x80, 0x04, 0x40, 0x08,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 011 (*)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x3f, 0xf8, 0x3f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 012 (+)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x06, 0x00, 0x07,
   0x00, 0x07, 0x00, 0x03, 0x80, 0x03, 0x80, 0x01,							// Char 013 (,)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x3f, 0xf8, 0x3f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 014 (-)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x0c, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 015 (.)
   0x08, 0x00, 0x08, 0x00, 0x10, 0x00, 0x10, 0x00, 0x30, 0x00, 0x20, 0x00,
   0x60, 0x00, 0x40, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x01, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0x06, 0x00, 0x04, 0x00, 0x0c,
   0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 016 (/)
   0xc0, 0x03, 0x20, 0x04, 0x10, 0x08, 0x10, 0x08, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x10, 0x08, 0x10, 0x08, 0x20, 0x04, 0xc0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 017 (0)
   0x80, 0x01, 0xe0, 0x01, 0x18, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0xf8, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 018 (1)
   0xc0, 0x03, 0x30, 0x0c, 0x10, 0x08, 0x08, 0x10, 0x08, 0x10, 0x00, 0x10,
   0x00, 0x08, 0x00, 0x0c, 0x00, 0x02, 0x00, 0x01, 0x80, 0x00, 0xc0, 0x00,
   0x20, 0x00, 0x10, 0x00, 0x08, 0x00, 0x04, 0x10, 0xfc, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 019 (2)
   0xe0, 0x03, 0x30, 0x06, 0x08, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08,
   0x00, 0x04, 0x80, 0x03, 0x00, 0x06, 0x00, 0x08, 0x00, 0x10, 0x00, 0x10,
   0x00, 0x10, 0x00, 0x10, 0x0c, 0x08, 0x18, 0x04, 0xe0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 020 (3)
   0x00, 0x06, 0x00, 0x05, 0x00, 0x05, 0x80, 0x04, 0x80, 0x04, 0x40, 0x04,
   0x40, 0x04, 0x20, 0x04, 0x20, 0x04, 0x10, 0x04, 0x10, 0x04, 0x08, 0x04,
   0xf8, 0x0f, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x80, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 021 (4)
   0xf8, 0x07, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00,
   0xe8, 0x03, 0x18, 0x0c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10,
   0x00, 0x10, 0x00, 0x00, 0x04, 0x08, 0x18, 0x04, 0xe0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 022 (5)
   0x00, 0x3e, 0x00, 0x21, 0x40, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
   0x10, 0x00, 0x10, 0x07, 0xd0, 0x18, 0x50, 0x00, 0x30, 0x20, 0x10, 0x20,
   0x10, 0x20, 0x00, 0x20, 0x20, 0x10, 0x40, 0x10, 0x80, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 023 (6)
   0xf8, 0x0f, 0x08, 0x08, 0x08, 0x08, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04,
   0x00, 0x04, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x01, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 024 (7)
   0xc0, 0x03, 0x30, 0x0c, 0x10, 0x08, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x10, 0x10, 0x10, 0x00, 0xe0, 0x07, 0x10, 0x08, 0x08, 0x18, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0x10, 0x00, 0x30, 0x0c, 0xc0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 025 (8)
   0x80, 0x03, 0x60, 0x08, 0x20, 0x00, 0x10, 0x00, 0x10, 0x20, 0x10, 0x20,
   0x10, 0x20, 0x20, 0x30, 0x60, 0x28, 0x80, 0x23, 0x00, 0x20, 0x00, 0x20,
   0x00, 0x00, 0x00, 0x10, 0x00, 0x08, 0x00, 0x06, 0xf0, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 026 (9)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x01, 0xc0, 0x03, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xc0, 0x03, 0x80, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 027 (:)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
   0x80, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x03, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x00, 0x60, 0x00,
   0x60, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 027 (;)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0c,
   0x00, 0x03, 0x80, 0x00, 0x60, 0x00, 0x18, 0x00, 0x06, 0x00, 0x18, 0x00,
   0x60, 0x00, 0x80, 0x00, 0x00, 0x03, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 029 (<)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 030 (=)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x18, 0x00,
   0x60, 0x00, 0x80, 0x00, 0x00, 0x03, 0x00, 0x0c, 0x00, 0x30, 0x00, 0x0c,
   0x00, 0x03, 0x80, 0x00, 0x60, 0x00, 0x18, 0x00, 0x04, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 031 (>)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0x60, 0x18, 0x20, 0x30,
   0x20, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x07,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x80, 0x07,
   0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 032 (?)
   0x00, 0x00, 0x80, 0x0f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x20,
   0x10, 0x20, 0x10, 0x3c, 0x10, 0x22, 0x10, 0x21, 0x10, 0x21, 0x10, 0x21,
   0x10, 0x22, 0x10, 0x7c, 0x10, 0x00, 0x10, 0x00, 0x20, 0x00, 0x20, 0x00,
   0x40, 0x18, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00,							// Char 033 (@)
   0x00, 0x00, 0xf8, 0x01, 0x80, 0x01, 0x80, 0x02, 0x40, 0x02, 0x40, 0x02,
   0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x10, 0x08, 0xf0, 0x0f, 0x10, 0x08,
   0x08, 0x10, 0x08, 0x10, 0x04, 0x20, 0x04, 0x20, 0x1f, 0xf8, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 034 (A)
   0x00, 0x00, 0xfc, 0x07, 0x10, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
   0x10, 0x08, 0x10, 0x08, 0xf0, 0x07, 0x10, 0x08, 0x10, 0x10, 0x10, 0x20,
   0x10, 0x20, 0x10, 0x20, 0x10, 0x20, 0x10, 0x10, 0xfc, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 035 (B)
   0x00, 0x00, 0xc0, 0x27, 0x10, 0x28, 0x08, 0x30, 0x04, 0x20, 0x04, 0x20,
   0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00,
   0x02, 0x00, 0x04, 0x20, 0x08, 0x10, 0x30, 0x08, 0xc0, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 036 (C)
	0x00, 0x00, 0xfc, 0x07, 0x10, 0x18, 0x10, 0x10, 0x10, 0x20, 0x10, 0x40,
   0x10, 0x40, 0x10, 0x40, 0x10, 0x40, 0x10, 0x40, 0x10, 0x40, 0x10, 0x40,
   0x10, 0x40, 0x10, 0x20, 0x10, 0x10, 0x10, 0x08, 0xfc, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 037 (D)
   0x00, 0x00, 0xfc, 0x3f, 0x10, 0x20, 0x10, 0x20, 0x10, 0x20, 0x10, 0x00,
   0x10, 0x02, 0x10, 0x02, 0xf0, 0x03, 0x10, 0x02, 0x10, 0x02, 0x10, 0x00,
   0x10, 0x40, 0x10, 0x40, 0x10, 0x40, 0x10, 0x40, 0xfc, 0x7f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 038 (E)
   0x00, 0x00, 0xfc, 0x3f, 0x10, 0x20, 0x10, 0x20, 0x10, 0x20, 0x10, 0x00,
   0x10, 0x02, 0x10, 0x02, 0xf0, 0x03, 0x10, 0x02, 0x10, 0x02, 0x10, 0x00,
   0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xfc, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 039 (F)
   0x00, 0x00, 0xc0, 0x27, 0x10, 0x38, 0x10, 0x20, 0x08, 0x20, 0x04, 0x00,
   0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0xff, 0x04, 0x20,
   0x04, 0x20, 0x08, 0x20, 0x10, 0x20, 0x20, 0x30, 0xc0, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 040 (G)
   0x00, 0x00, 0x3e, 0x7c, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0xf8, 0x1f, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x3e, 0x7c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 041 (H)
   0x00, 0x00, 0xfc, 0x1f, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xfc, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 042 (I)
   0x00, 0x00, 0xc0, 0x7f, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08,
   0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x04, 0x08, 0x04, 0x08,
   0x04, 0x08, 0x04, 0x08, 0x04, 0x04, 0x18, 0x06, 0xe0, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 043 (J)
   0x00, 0x00, 0x7c, 0xf0, 0x10, 0x20, 0x10, 0x10, 0x10, 0x08, 0x10, 0x04,
   0x10, 0x03, 0x90, 0x00, 0xd0, 0x00, 0x30, 0x01, 0x10, 0x02, 0x10, 0x04,
   0x10, 0x08, 0x10, 0x08, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x70, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 044 (K)
   0x00, 0x00, 0xfc, 0x01, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
   0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x20,
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xfc, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 045 (L)
   0x00, 0x00, 0x0f, 0xf0, 0x0c, 0x30, 0x14, 0x28, 0x14, 0x28, 0x24, 0x24,
   0x24, 0x24, 0x44, 0x24, 0x44, 0x22, 0x84, 0x22, 0x84, 0x20, 0x04, 0x21,
   0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x1f, 0xf8, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 046 (M)
   0x00, 0x00, 0x0e, 0x7c, 0x18, 0x10, 0x18, 0x10, 0x28, 0x10, 0x28, 0x10,
   0x48, 0x10, 0x88, 0x10, 0x88, 0x10, 0x08, 0x11, 0x08, 0x11, 0x08, 0x12,
   0x08, 0x12, 0x08, 0x14, 0x08, 0x18, 0x08, 0x18, 0x3e, 0x10, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 047 (N)
   0x00, 0x00, 0xc0, 0x03, 0x30, 0x0c, 0x08, 0x10, 0x0c, 0x30, 0x04, 0x20,
   0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40,
   0x04, 0x20, 0x04, 0x20, 0x08, 0x10, 0x30, 0x0c, 0xe0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 048 (O)
   0x00, 0x00, 0xfc, 0x07, 0x10, 0x08, 0x10, 0x10, 0x10, 0x20, 0x10, 0x20,
   0x10, 0x20, 0x10, 0x20, 0x10, 0x10, 0x10, 0x08, 0xf0, 0x07, 0x10, 0x00,
   0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xfc, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 049 (P)
   0x00, 0x00, 0xc0, 0x03, 0x30, 0x0c, 0x08, 0x10, 0x04, 0x20, 0x04, 0x20,
   0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40,
   0x04, 0x20, 0x04, 0x20, 0x08, 0x10, 0x30, 0x0c, 0xc0, 0x03, 0x40, 0x00,
   0xc0, 0x47, 0x20, 0x38, 0x00, 0x00, 0x00, 0x00,							// Char 050 (Q)
   0x00, 0x00, 0xfc, 0x07, 0x10, 0x18, 0x10, 0x10, 0x10, 0x20, 0x10, 0x20,
   0x10, 0x20, 0x10, 0x10, 0x10, 0x18, 0xf0, 0x07, 0x10, 0x04, 0x10, 0x08,
   0x10, 0x10, 0x10, 0x20, 0x10, 0x20, 0x10, 0x40, 0x7c, 0xc0, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 051 (R)
   0x00, 0x00, 0xc0, 0x17, 0x30, 0x1c, 0x08, 0x18, 0x08, 0x10, 0x08, 0x10,
   0x18, 0x00, 0x30, 0x00, 0xc0, 0x03, 0x00, 0x0c, 0x00, 0x18, 0x00, 0x10,
   0x04, 0x10, 0x04, 0x10, 0x0c, 0x08, 0x1c, 0x0c, 0xe4, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 052 (S)
   0x00, 0x00, 0xfc, 0x7f, 0x04, 0x41, 0x04, 0x41, 0x04, 0x41, 0x04, 0x41,
   0x04, 0x41, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0xe0, 0x0f, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 053 (T)
   0x00, 0x00, 0x3e, 0x7c, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0x10, 0x08, 0x20, 0x04, 0xc0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 054 (U)
   0x00, 0x00, 0x1f, 0xf8, 0x04, 0x20, 0x04, 0x20, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x10, 0x08, 0x10, 0x08, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04,
   0x40, 0x02, 0x40, 0x02, 0x40, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 055 (V)
   0x00, 0x00, 0x3f, 0xf8, 0x04, 0x40, 0x04, 0x40, 0x04, 0x40, 0x04, 0x43,
   0x04, 0x43, 0x88, 0x24, 0x88, 0x24, 0x88, 0x24, 0x48, 0x24, 0x48, 0x24,
   0x48, 0x28, 0x28, 0x28, 0x28, 0x18, 0x38, 0x30, 0x10, 0x10, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 056 (W)
   0x00, 0x00, 0x1e, 0x3c, 0x08, 0x08, 0x10, 0x04, 0x10, 0x04, 0x20, 0x02,
   0x40, 0x01, 0x80, 0x01, 0x80, 0x00, 0x40, 0x01, 0x20, 0x01, 0x20, 0x02,
   0x10, 0x04, 0x08, 0x08, 0x08, 0x08, 0x04, 0x10, 0x3e, 0x7c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 057 (X)
   0x00, 0x00, 0x3c, 0x78, 0x08, 0x20, 0x10, 0x10, 0x20, 0x08, 0x20, 0x08,
   0x40, 0x04, 0x80, 0x02, 0x80, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0xe0, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 058 (Y)
   0x00, 0x00, 0xf8, 0x1f, 0x08, 0x10, 0x08, 0x08, 0x08, 0x04, 0x08, 0x04,
   0x00, 0x02, 0x00, 0x01, 0x80, 0x00, 0x80, 0x00, 0x40, 0x00, 0x20, 0x10,
   0x20, 0x10, 0x10, 0x10, 0x08, 0x10, 0x04, 0x10, 0xfc, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 059 (Z)
   0x80, 0x07, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00,							// Char 060 ([)
   0x08, 0x00, 0x08, 0x00, 0x10, 0x00, 0x10, 0x00, 0x30, 0x00, 0x20, 0x00,
   0x60, 0x00, 0x40, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x01, 0x00, 0x01,
   0x00, 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0x06, 0x00, 0x04, 0x00, 0x0c,
   0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 061 (\)
   0xf0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 062 (])
   0x00, 0x00, 0x80, 0x01, 0xc0, 0x01, 0x40, 0x02, 0x20, 0x04, 0x10, 0x08,
   0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 063 (^)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x00,							// Char 064 (_)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,
   0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 065 (`)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03,
   0x18, 0x04, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0xe0, 0x0f, 0x18, 0x08,
   0x04, 0x08, 0x04, 0x08, 0x04, 0x0c, 0x0c, 0x0a, 0xf0, 0x38, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 066 (a)
   0x07, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0xc4, 0x03,
   0x34, 0x0c, 0x0c, 0x10, 0x0c, 0x10, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
   0x04, 0x20, 0x0c, 0x10, 0x0c, 0x10, 0x34, 0x0c, 0xc7, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 067 (b)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x17,
   0x10, 0x18, 0x08, 0x10, 0x04, 0x10, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00,
   0x04, 0x00, 0x04, 0x00, 0x08, 0x20, 0x30, 0x1c, 0xc0, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 068 (c)
   0x00, 0x1c, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0xc0, 0x13,
   0x30, 0x14, 0x08, 0x18, 0x08, 0x18, 0x04, 0x10, 0x04, 0x10, 0x04, 0x10,
   0x04, 0x10, 0x04, 0x18, 0x08, 0x18, 0x10, 0x14, 0xe0, 0x73, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 069 (d)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x07,
   0x30, 0x08, 0x08, 0x10, 0x04, 0x20, 0x04, 0x20, 0xfc, 0x3f, 0x04, 0x00,
   0x04, 0x00, 0x08, 0x00, 0x08, 0x20, 0x30, 0x18, 0xc0, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 070 (e)
   0x00, 0x3f, 0x80, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0xf8, 0x1f,
   0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00,
   0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0xf8, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 071 (f)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x73,
   0x10, 0x14, 0x08, 0x18, 0x08, 0x18, 0x04, 0x10, 0x04, 0x10, 0x04, 0x10,
   0x04, 0x10, 0x04, 0x18, 0x08, 0x18, 0x10, 0x14, 0xe0, 0x13, 0x00, 0x10,
   0x00, 0x10, 0x00, 0x10, 0x00, 0x0c, 0xe0, 0x03,							// Char 072 (g)
   0x0e, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0xc8, 0x07,
   0x28, 0x08, 0x18, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x3e, 0x7c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 073 (h)
   0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xfc, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 074 (i)
   0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x07,
   0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04,
   0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04,
   0x00, 0x04, 0x00, 0x04, 0x00, 0x02, 0xfc, 0x01,							// Char 075 (j)
   0x1c, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x7c,
   0x10, 0x08, 0x10, 0x04, 0x10, 0x02, 0x90, 0x00, 0x50, 0x00, 0xb0, 0x00,
   0x10, 0x01, 0x10, 0x02, 0x10, 0x04, 0x10, 0x08, 0x1c, 0x7c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 076 (k)
   0xf8, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xfc, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 077 (l)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x18,
   0x94, 0x26, 0x0c, 0x41, 0x04, 0x41, 0x04, 0x41, 0x04, 0x41, 0x04, 0x41,
   0x04, 0x41, 0x04, 0x41, 0x04, 0x41, 0x04, 0x41, 0x1f, 0xc7, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 078 (m)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xce, 0x07,
   0x28, 0x08, 0x18, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x3e, 0x7c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 079 (n)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03,
   0x30, 0x0c, 0x08, 0x10, 0x08, 0x10, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
   0x04, 0x20, 0x08, 0x10, 0x08, 0x10, 0x30, 0x0c, 0xc0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 080 (o)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x03,
   0x34, 0x0c, 0x0c, 0x10, 0x0c, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
   0x04, 0x20, 0x0c, 0x10, 0x0c, 0x10, 0x34, 0x08, 0xc4, 0x07, 0x04, 0x00,
   0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x3f, 0x00,							// Char 081 (p)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x73,
   0x10, 0x14, 0x08, 0x18, 0x08, 0x10, 0x04, 0x10, 0x04, 0x10, 0x04, 0x10,
   0x04, 0x10, 0x04, 0x18, 0x08, 0x18, 0x10, 0x14, 0xe0, 0x13, 0x00, 0x10,
   0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x7e,							// Char 082 (q)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x1c,
   0x20, 0x23, 0xa0, 0x00, 0x60, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
   0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0xfc, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 083 (r)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x17,
   0x10, 0x18, 0x08, 0x10, 0x08, 0x00, 0x18, 0x00, 0xe0, 0x07, 0x00, 0x08,
   0x00, 0x10, 0x04, 0x10, 0x0c, 0x10, 0x1c, 0x0c, 0xe4, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 084 (s)
   0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0xfc, 0x1f,
   0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
   0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x40, 0x60, 0x80, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 085 (t)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1c,
   0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10,
   0x08, 0x10, 0x08, 0x10, 0x08, 0x18, 0x10, 0x14, 0xe0, 0x73, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 086 (u)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x7c,
   0x08, 0x10, 0x08, 0x10, 0x10, 0x08, 0x10, 0x08, 0x20, 0x04, 0x20, 0x04,
   0x20, 0x02, 0x40, 0x02, 0x40, 0x02, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 087 (v)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0,
   0x04, 0x40, 0x04, 0x40, 0x04, 0x40, 0x08, 0x41, 0x88, 0x22, 0x88, 0x22,
   0x48, 0x24, 0x08, 0x28, 0x30, 0x38, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 088 (w)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x1e,
   0x08, 0x08, 0x10, 0x04, 0x20, 0x02, 0x40, 0x01, 0x80, 0x00, 0x40, 0x01,
   0x20, 0x02, 0x10, 0x04, 0x08, 0x08, 0x04, 0x10, 0x3e, 0x3e, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 089 (x)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xf8,
   0x08, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x08, 0x20, 0x08, 0x20, 0x08,
   0x40, 0x04, 0x40, 0x04, 0x80, 0x02, 0x80, 0x03, 0x00, 0x01, 0x00, 0x01,
   0x80, 0x00, 0x80, 0x00, 0x40, 0x00, 0xfc, 0x01,							// Char 090 (y)
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1f,
   0x08, 0x10, 0x08, 0x08, 0x00, 0x04, 0x00, 0x02, 0x00, 0x01, 0x80, 0x00,
   0x40, 0x00, 0x20, 0x00, 0x10, 0x10, 0x08, 0x10, 0xf8, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 091 (z)
   0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x60, 0x00, 0xc0, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,							// Char 092 ({)
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,							// Char 093 (|)
   0x00, 0x00, 0x60, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00,
   0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
   0x40, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00							// Char 094 (})
};  */

prog_uint16_t Lookup(char input)
{
	prog_uint16_t  position;
	switch (input)
    {
      case ' ':
        position =  0;
		break;
      case 'A':
		position = 1452;
		break;
      case 'a':
		position = 2860;
		break;
      case 'B':
		 position =  1496;
		 break;
      case 'b':
		position = 2904 ;
		break;	
      case 'C':
		position =  1540;
		break;
      case 'c':
        position = 2948;
		break;
      case 'D':
		position =  1584; 
		break;
      case 'd':
		position = 2992;
		break;
      case 'E':
		position = 1628;
		break;
      case 'e':
		position = 3036;
		break;
      case 'F':
		position = 1672;
		break;
      case 'f':
		 position = 3080 ;
		break;
      case 'G':
		position = 1716;
		break;
      case 'g':
        position = 3124 ;
		break;
      case 'H':
		position = 1760 ;
		break;
      case 'h':
		position = 3168 ;
		break;
      case 'I':
		position = 1804 ;
		break;
      case 'i':
		position = 3212 ;
		break;
      case 'J':
		position =1848 ;
		break;
      case 'j':
		position = 3256;
		break;
      case 'K':
		position = 1892;
		break;
      case 'k':
       position = 3300;
		break;
      case 'L':
	   position = 1936 ;
		break;
      case 'l':
		position = 3344 ;
		break;         
      case 'M':
		position = 1980;
		break;
      case 'm':
        position = 3388 ;
		break;
      case 'N':
		position = 2024;
		break;
      case 'n':
		position = 3432;
		break;
      case 'O':
		position = 2068;
		break;
      case 'o':
        position = 3476;
		break;
      case 'P':
		position = 2112;
		break;
      case 'p':
        position = 3520;
		break;
      case 'Q':
		position = 2156;
		break;
      case 'q':
        position = 3564;
		break;
      case 'R':
		position = 2200;
		break;
      case 'r':
        position = 3608;
		break;
      case 'S':
		position = 2244;
		break;
      case 's':
        position = 3652;
		break;
      case 'T':
		position = 2288;
		break;
      case 't':
		position = 3696;
		break;
      case 'U':
		position = 2332;
		break;
      case 'u':
        position = 3740;
		break;
      case 'V':
		position = 2376;
		break;
      case 'v':
        position = 3784;
		break;
      case 'W':
		position = 2420;
		break;
      case 'w':
		position = 3828;
		break;
      case 'X':
		position = 2404;
		break;
      case 'x':
       position = 3872;
		break;
      case 'Y':
		position = 2508;
		break;
      case 'y':
        position = 3916;
		break;
      case 'Z':
		position = 2552;
		break;
      case 'z':
        position = 3960;
		break;
      case '0':
		position = 704;
		break;
      case '1':
		position = 748;
		break;
      case '2':
		position = 792;
		break;
      case '3':
    	position = 836;
		break;  
      case '4':
    	position = 880;
		break;
      case '5':
     	position = 924;
		break;
      case '6':
    	position = 968;
		break;
      case '7':
   		position = 1012;
		break;
      case '8':
  		position = 1056;
		break;
      case '9':
    	position = 1100;
		break;
      case '!':
    	position = 44;
		break;
      case '"':
    	position = 88;
		break;
	  case '#':
    	position = 132;
		break;
      case '$':
    	position = 176;
		break;
      case '%':
    	position = 220;
		break;
      case '&':
    	position = 264;
		break;
      case '(':
    	position = 352;
		break;
      case ')':
    	position = 396 ;
		break;
      case '*':
    	position = 440;
		break;
      case '+':
    	position = 484;
		break;
      case ',':
    	position = 528;
		break;
      case '-':
    	position = 572;
		break;
      case '.':
    	position = 616;
		break;
      case '/':
    	position = 660;
		break;
	  case ':':
    	position = 1144;
		break;
      case ';':
    	position = 1188;
		break;
      case '<':
    	position = 1232;
		break;
      case '=':
    	position = 1276;
		break;
      case '>':
    	position = 1320;
		break;
      case '?':
    	position = 1364;
		break;
      case '@':
    	position = 1408;
		break;
      case '[':
    	position = 2596;
		break;
      case ']':
    	position = 2684;
		break;
      case '^':
    	position = 2728;
		break;
      case '_':
    	position = 2772;
		break;
      case '{':
    	position = 4004;
		break;
      case '|':
    	position = 4048;
		break;
	  case '}':
    	position = 4092;
		break;
	  case '\'':
    	position = 2816;
		break;
		
	  case '\n':
    	position = 0;
		break;
    }
	
	return position;	

}