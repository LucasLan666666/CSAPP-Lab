/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

    Replace the "return" statement in each function with one
    or more lines of C code that implements the function. Your code
    must conform to the following style:

    int Funct(arg1, arg2, ...) {
        /* brief description of how your implementation works */
        int var1 = Expr1;
        ...
        int varM = ExprM;

        varJ = ExprJ;
        ...
        varN = ExprN;
        return ExprR;
    }

    Each "Expr" is an expression using ONLY the following:
    1. Integer constants 0 through 255 (0xFF), inclusive. You are
        not allowed to use big constants such as 0xffffffff.
    2. Function arguments and local variables (no global variables).
    3. Unary integer operations ! ~
    4. Binary integer operations & ^ | + << >>

    Some of the problems restrict the set of allowed operators even further.
    Each "Expr" may consist of multiple operators. You are not restricted to
    one operator per line.

    You are expressly forbidden to:
    1. Use any control constructs such as if, do, while, for, switch, etc.
    2. Define or use any macros.
    3. Define any additional functions in this file.
    4. Call any functions.
    5. Use any other operations, such as &&, ||, -, or ?:
    6. Use any form of casting.
    7. Use any data type other than int.  This implies that you
        cannot use arrays, structs, or unions.


    You may assume that your machine:
    1. Uses 2s complement, 32-bit representations of integers.
    2. Performs right shifts arithmetically.
    3. Has unpredictable behavior when shifting if the shift amount
        is less than 0 or greater than 31.


    EXAMPLES OF ACCEPTABLE CODING STYLE:
    /*
    * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
    */
    int pow2plus1(int x) {
        /* exploit ability of shifts to compute powers of 2 */
        return (1 << x) + 1;
    }

    /*
    * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
    */
    int pow2plus4(int x) {
        /* exploit ability of shifts to compute powers of 2 */
        int result = (1 << x);
        result += 4;
        return result;
    }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
    1. Define or use any macros.
    2. Define any additional functions in this file.
    3. Call any functions.
    4. Use any form of casting.
    5. Use any data type other than int or unsigned.  This means that you
        cannot use arrays, structs, or unions.
    6. Use any floating point data types, operations, or constants.


NOTES:
    1. Use the dlc (data lab checker) compiler (described in the handout) to
        check the legality of your solutions.
    2. Each function has a maximum number of operations (integer, logical,
        or comparison) that you are allowed to use for your implementation
        of the function.  The max operator count is checked by dlc.
        Note that assignment ('=') is not counted; you may use as many of
        these as you want without penalty.
    3. Use the btest test harness to check your functions for correctness.
    4. Use the BDD checker to formally verify your functions
    5. The maximum number of ops for each function is given in the
        header comment for each function. If there are any inconsistencies
        between the maximum ops in the writeup and in this file, consider
        this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // 利用德摩根律即可
    return ~(x & y) & ~(~x & ~y);
}


/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    return 0x01 << 31;
}


//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // 补码最大数 + 1 与自己异或得到 -1，同时排除 -1 的影响
    int y = x + 0x01; // x == 0x7FFFFFFF, y == 0x80000000; x = 0xFFFFFFFF, y == 0x0
    return !(((x ^ y) + 0x01) | !y);
}


/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    // 利用左移构建一个 0xAAAAAAAA 掩码
    int mask = 0xAA << 24 | 0xAA << 16 | 0xAA << 8 | 0xAA;
    // 只有奇数位全为 1 时，返回值才为 1
    return !((x & mask) ^ mask);
}


/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    return ~x + 1;
}


//3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // 最高位为 1 表示“是”
    int lessThan0x30 = x + ~0x2F; // 补码是按位取反 + 1，这样节省一个 + 号
    int greaterThan0x39 = ~x + 0x3A; // 同理
    return !((lessThan0x30 | greaterThan0x39) >> 31);
}


/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    /**
     * x 非零时，y & 0xFFFFFFFF
     * x 为零时，z & 0xFFFFFFFF
     * 可以生成一个掩码
     */
    int mask = ~(!!x << 0) + 1; // !!x 是一个布尔表达式，左移零位可以将其转换为整型
    return (mask & y) | (~mask & z);
}


/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    /**
     * 考虑到溢出，所以分多情况讨论：
     * 1. x 为负，y 为正，直接出结果
     * 2. x 为负和 y 为正至少满足一个条件时，判断 y - x 的正负
     */
    return (!(~(x >> 31) | (y >> 31))) | (!(~(x >> 31) & (y >> 31)) & !((~x + 1 + y) >> 31));
}


//4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
    /**
     * x 和自己的补码按位或
     * 只要 x 非零，那么结果的最高位一定是 1
     * 接下来右移 31 位取反，再和 1 按位与
     */
    return ~((x | (~x + 1)) >> 31) & 0x01;
}


/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    // 重点运用二分法思想
    int pos_x = x ^ (x >> 31); // 获取 x 的正值（x 为 -1，-2，-4···的时候，不需要额外补充符号位），这里用的是按位取反的方法，并非补码，巧妙处理了这一细节
    int isZeroOrNegOne = !pos_x; // 只有 -1 和 0 能使得 isZeroOrNegOne == 1，这两个数特殊，需要单独考虑
    int notZeroOrNegOneMask = (!!pos_x << 31) >> 31; // 只有 pos_x 不等于 0 或 -1 的时候，该掩码为 0xFFFFFFFF，否则为 0x0
    int bit_16, bit_8, bit_4, bit_2, bit_1;
    int bit_count;
    bit_16 = !!(pos_x >> 16) << 4;
    pos_x = pos_x >> bit_16;
    bit_8 = !!(pos_x >> 8) << 3;
    pos_x = pos_x >> bit_8;
    bit_4 = !!(pos_x >> 4) << 2;
    pos_x = pos_x >> bit_4;
    bit_2 = !!(pos_x >> 2) << 1;
    pos_x = pos_x >> bit_2;
    bit_1 = !!(pos_x >> 1);
    bit_count = bit_16 + bit_8 + bit_4 + bit_2 + bit_1 + 2; // 1 bit 给少算的一位，1 bit 给符号位
    return isZeroOrNegOne | (bit_count & notZeroOrNegOneMask); // x 等于 0 或 -1 时算的不对，需要分两种情况讨论
}


//float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned    s = uf >> 31;
    unsigned  exp = (uf >> 23) & 0xFF;
    unsigned frac = (uf << 9) >> 9;

    // 特殊数，原封不动
    if (exp == 0xFF) {
        ;
    }
    // 非规格化数
    else if (!exp) {
        if (frac >> 22) { // 尾数溢出，阶码从 0 变为 1
            exp = 0x01;
        }
        frac = (frac << 10) >> 9; // 通过移位实现 * 2 操作
    }
    // 规格化数
    else {
        exp = exp + 0x01; // 只需要操作阶码
    }

    return (s << 31) + (exp << 23) + frac;
}


/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    // (int)f 是向零舍入
    unsigned      s = uf >> 31;
    unsigned    exp = (uf >> 23) & 0xFF;
    unsigned   frac = (uf << 9) >> 9;
    unsigned      f = (1 << 23) + frac; // 规格化数真正的小数部分
    int           E = exp - 127 - 23; // 代表右移的位数
    int      sign_E = E >> 31; // 全为 1 表示幂为负，全为 0 表示 E 为正
    unsigned  pos_E = (E ^ sign_E) + (sign_E & 0x01); // 2 的幂取绝对值，方便移位
    unsigned  pos_r; // 结果的绝对值

    // 非规格化数或很小的规格化数
    if (!exp || exp < 127) {
        return 0;
    }
    // 特殊数或过大的规格化数，返回 0x80000000u
    else if (exp == 255 || E > 7) {
        return 0x01 << 31;
    }
    // 规格化数，对于负数要用补码的算法
    else {
        pos_r = ~(0x01 << 31) & (sign_E ? (f >> pos_E) : (f << pos_E));
        return s ? (~pos_r + 0x01) : pos_r;
    }
}


/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    /**
     * 只考虑 2 的幂：
     * float 类型所能表示的最小非规格化数是 0 00000000 00000000000000000000001  -> 2^(-23) * 2^(-126) = 2^(-149)
     * float 类型所能表示的最大非规格化数是 0 00000000 10000000000000000000000  -> 2^(-1) * 2^(-126) = 2^(-127)
     * float 类型所能表示的最小规格化数是   0 00000001 00000000000000000000000  -> 2^0 * 2^(1 - 127) = 2^(-126)
     * float 类型所能表示的最大规格化数是   0 11111110 00000000000000000000000  -> 2^0 * 2^(254 - 127) = 2^127
     */
    // 太小了
    if (x < -149) {
        return 0;
    }
    // 非规格化数
    else if (x >= -149 && x <=-127) {
        return 0x01 << (x + 149);
    }
    // 规格化数
    else if (x >= -126 && x <= 127) {
        return (x + 127) << 23;
    }
    // 太大了
    else {
        return 0xFF << 23;
    }
}
