/*
  PPUCMatrix.h
  Created by Markus Kalkbrenner, 2020-2021.

  Play more pinball!
*/

// WPC matrix numbering:
//
//    | C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8
// ---+----+----+----+----+----+----+----+----
// R1 | 11 | 21 | 31 | 41 | 51 | 61 | 71 | 81
// ---+----+----+----+----+----+----+----+----
// R2 | 12 | 22 | 32 | 42 | 52 | 62 | 72 | 82
// ---+----+----+----+----+----+----+----+----
// R3 | 13 | 23 | 33 | 43 | 53 | 63 | 73 | 83
// ---+----+----+----+----+----+----+----+----
// R4 | 14 | 24 | 34 | 44 | 54 | 64 | 74 | 84
// ---+----+----+----+----+----+----+----+----
// R5 | 15 | 25 | 35 | 45 | 55 | 65 | 75 | 85
// ---+----+----+----+----+----+----+----+----
// R6 | 16 | 26 | 36 | 46 | 56 | 66 | 76 | 86
// ---+----+----+----+----+----+----+----+----
// R7 | 17 | 27 | 37 | 47 | 57 | 67 | 77 | 87
// ---+----+----+----+----+----+----+----+----
// R8 | 18 | 28 | 38 | 48 | 58 | 68 | 78 | 88

// DE matrix numbering:
//
//    | C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8
// ---+----+----+----+----+----+----+----+----
// R1 |  1 |  9 | 17 | 25 | 33 | 41 | 49 | 57
// ---+----+----+----+----+----+----+----+----
// R2 |  2 | 10 | 18 | 26 | 34 | 42 | 50 | 58
// ---+----+----+----+----+----+----+----+----
// R3 |  3 | 11 | 19 | 27 | 35 | 43 | 51 | 59
// ---+----+----+----+----+----+----+----+----
// R4 |  4 | 12 | 20 | 28 | 36 | 44 | 52 | 60
// ---+----+----+----+----+----+----+----+----
// R5 |  5 | 13 | 21 | 29 | 37 | 45 | 53 | 61
// ---+----+----+----+----+----+----+----+----
// R6 |  6 | 14 | 22 | 30 | 38 | 46 | 54 | 62
// ---+----+----+----+----+----+----+----+----
// R7 |  7 | 15 | 23 | 31 | 39 | 47 | 55 | 63
// ---+----+----+----+----+----+----+----+----
// R8 |  8 | 16 | 24 | 32 | 40 | 48 | 56 | 64

#ifndef PPUCMatrix_h
#define PPUCMatrix_h

#include <Arduino.h>
#include <PPUCEventDispatcher.h>
#include <PPUCEvent.h>

#ifndef MAX_FIELDS_REGISTERED
#define MAX_FIELDS_REGISTERED 72
#endif

#ifndef NUM_COLS
#define NUM_COLS 9
#endif

class PPUCMatrix {
public:
    PPUCMatrix(PPUCEventDispatcher* eD);

    virtual void start() = 0;

    virtual void stop() = 0;

    void update();

    void print();

    void setLastColToRead(byte lastColToRead);

    void registerFieldAsEvent(byte row, byte column, byte number);

    void registerAllFieldsAsEvent(String pinballType);

    static void _readRow() {}

    volatile byte lastColToRead;
    volatile byte rows[NUM_COLS];

protected:
    PPUCEventDispatcher* eventDispatcher;

    char eventSource;
    char system = 'D'; // W => WPC, D => DE

    byte previousRows[NUM_COLS];

    int registeredFieldsCounter = -1;
    word registeredFieldRowCol[MAX_FIELDS_REGISTERED];
    byte registeredFieldNum[MAX_FIELDS_REGISTERED];
};

#endif
