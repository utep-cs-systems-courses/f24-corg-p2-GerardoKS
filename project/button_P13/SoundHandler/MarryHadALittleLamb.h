#define a 4545
#define f 5600
#define e 6050
#define d 6800
#define n 0

#define staccato 25
#define quarter 125
#define half 250
#define whole 500


const int note[] = {f, n, e, n, d, n, e, n, f, n, f, n, f, n, e, n, e, n, e, n, f, n, a, n, a, n, f, n, e, n, d, n, e, n, f, n, f, n, f, n, f, n, e, n, e, n, f, n, e, n, d, n};
const int duration[] = {quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, half, staccato, quarter, staccato, quarter, staccato, half, staccato, quarter, staccato, quarter, staccato, half, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, quarter, staccato, whole, staccato};


void play();