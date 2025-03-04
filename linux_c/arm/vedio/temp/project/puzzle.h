typedef struct _BmpFileHead {
  unsigned short bfType;
  unsigned long bfSize;
  unsigned short bfResvered1;
  unsigned short bfResvered2;
  unsigned long bfOffBits;
} BmpFileHead;

typedef struct _BmpInfoHead {
  unsigned long biSize;
  unsigned long biWidth;
  unsigned long biHeight;
  unsigned short biPlanes;
  unsigned short biBitCount;
  unsigned long biCompression;
  unsigned long biSizeImage;
  long biXPelsPerMeter;
  long biYPelsPerMeter;
  unsigned long biClrUsed;
  unsigned long biClrImportant;
} BmpInfoHead;

void puzzle();
