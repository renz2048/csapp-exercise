#### Practice Problem 2.1

A. 0x39A7F8 to binary

0011 1001 1010 0111 1111 1000

B. Binary 1100 1001 0111 1011 to hexadecimal

0xC97B

C. 0xD5E4C to binary

1101 0101 1110 0100 1100

D. Binary 10 0110 1110 0111 1011 0101 to hexadecimal

0x26E7B5

#### Practice Problem 2.2

| n         | $2^n$(Decimal) | $2^n$(Hexadeciaml)    |
| --------- | -------------- | --------------------- |
| 9         | 512            | 0x200                 |
| 19        | <u>524288</u>  | <u>0x80000(3+4x4)</u> |
| <u>14</u> | 16384          | <u>0x4000</u>         |
| <u>16</u> | <u>6536</u>    | 0x10000               |
| 17        | <u>131072</u>  | <u>0x20000</u>        |
| <u>5</u>  | 32             | <u>0x20</u>           |
| <u>7</u>  | <u>128</u>     | 0x80                  |

#### Practice Problem 2.3

| Decimal    | Binary           | hexadecimal |
| ---------- | ---------------- | ----------- |
| 0          | 0000 0000        | 0x00        |
| 167        | <u>1010 0111</u> | <u>0xA7</u> |
| 62         | <u>0011 1110</u> | <u>0x3E</u> |
| 188        | <u>1011 1100</u> | <u>0xBC</u> |
| <u>55</u>  | 0011 0111        | <u>0x37</u> |
| <u>136</u> | 1000 1000        | <u>0x88</u> |
| <u>243</u> | 1111 0011        | <u>0xF3</u> |
| <u>82</u>  | <u>0101 0010</u> | 0x52        |
| <u>172</u> | <u>1010 1100</u> | 0xAC        |
| <u>231</u> | <u>1110 0111</u> | 0xE7        |

#### Practice Problem 2.4

A. 0x503c + 0x8 = <u>0x5046</u>

B. 0x503c - 0x40 = <u>0x4ffc</u>

C. 0x03c + 64 = <u>0x5042</u>

D. 0x50ea - 0x503c = <u>0x50ae</u>

#### Practice Problem 2.5

Little-endian:

```
~ ./pp2_5 
 21
 21 43
 21 43 65
```

A. Little endian:<u>21</u>	        Big endian:<u>87</u>

B. Little endian:<u>21 43</u>	        Big endian:<u>87 65</u>

C. Little endian:<u>21 43 65</u>	Big endian:<u>87 65 43</u>

#### Practice Problem 2.7

```
~ ./pp2_7
 61 62 63 64 65 66
```

#### show-bytes.c

```
~ ./show_bytes
 39 30 00 00
 00 e4 40 46
 98 47 ab ac fc 7f 00 00
```

#### Practice Problem 2.10

```
1 void inplace_swap(int *x, int *y) {
2   *y = *x ^ *y; /* Step 1 */
3   *x = *x ^ *y; /* Step 2 */
4   *y = *x ^ *y; /* Step 3 */
5 }
```
##### Steps

| Step      |         *x         |          *y          |
| :-------- | :----------------: | :------------------: |
| Initially |         a          |          b           |
| Step1     |      <u>a</u>      |      <u>a^b</u>      |
| Step2     | <u>a^(a^b) = b</u> |      <u>a^b</u>      |
| Step2     | <u>a^(a^b) = b</u> | <u>a^(a^b)^(a^b)</u> |

##### theory

a^b=b^a

a^a=0

a^0=a

^判断是否相同

#### Practice Problem 2.11

```
~ ./pp2_11.bin 
 4 3 2 1
 5 4 0 2 1
```

##### modification

change `<=` to `<`

```
void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt-1;
      first < last;
      first++, last--)
    inplace_swap(&a[first],&a[last]);
}
```

#### Practice Problem 2.12

A. x & 0xFF

B. (x & 0xFF) | ((~x) & 0xFFFFFF00)

C. x | 0xFF

#### Practice Problem 2.13

##### analysis

1. bis(bit set)

int bis(int x, int m);

set *z* to 1 at each bit position where *m* is 1

| 运算       | 规则                       |
| ---------- | -------------------------- |
| x \| m     | 当m对应bit为1，x对应bit为1 |
| bis(x,  m) | 当m对应bit为1，x对应bit为1 |

可以看出`bis(x, m) = x | m`

2. bic(bit clear)

int bic(int x, int m);

set *z* to 0 at each bit position where *m* is 1

| 运算      | 规则                       |
| --------- | -------------------------- |
| x & m     | 当m对应bit为0，x对应bit为0 |
| bic(x, m) | 当m对应bit为1，x对应bit为0 |

可以看出`bic(x, m) = x & (~m)`

异或运算：`x ^ y = ((~x) & y) | ( x & (~y))`

##### solution

```
/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, inty) {
  int result = bis(x, y);
  return result;
}
```

```
/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
  int result = bis( bic(x, y), bic(y, x));
  return result;
}
```

#### Practice Problem 2.14

x = 0x66 = [0110 0110]

y = 0x39 = [0011 1001]

| Expression | Value              | Expression | Value |
| ---------- | ------------------ | ---------- | ----- |
| x & y      | [0010 0000] = 0x20 | x && y     | 0x01  |
| x \| y     | [0111 1111] = 0x7F | x \|\| y   | 0x01  |
| ~x \| ~y   | [1101 1111] = 0xDF | !x \|\| !y | 0x00  |
| x & ! y    | [0000 0000] = 0x00 | x && ~y    | 0x00  |

#### Practice Problem 2.15

`x ^ y ? 1:0;`

#### Practice Problem 2.16

|            x             |               x << 3               |       x >> 2(Logical)        |      x >> 2(Arithmetic)      |
| :----------------------: | :--------------------------------: | :--------------------------: | :--------------------------: |
|       Hex  Bianry        |       Binary            Hex        |       Binary      Hex        |       Binary      Hex        |
|  0xC3  <u>1100 0011</u>  | <u>110 0001 1000</u>  <u>0x618</u> | <u>0011 0000</u> <u>0x30</u> | <u>1111 0000</u> <u>0xf0</u> |
| 0x75    <u>0111 0101</u> | <u>011 1010 1000</u> <u>0x3a8</u>  | <u>0001 1101</u> <u>0x1d</u> | <u>0001 1101</u> <u>0x1d</u> |
| 0x87    <u>1000 0111</u> | <u>100 0011 1000</u> <u>0x438</u>  | <u>0010 0001</u> <u>0x21</u> | <u>1110 0001</u> <u>0xe1</u> |
| 0x66    <u>0110 0110</u> | <u>011 0011 0000</u> <u>0x330</u>  | <u>0001 1001</u> <u>0x19</u> | <u>0001 1001</u> <u>0x19</u> |

#### Practice Problem 2.17

| Hexadecimal | Binary        | $B2U~4~$(x)                        | $B2T~4~(x)$                         |
| ----------- | ------------- | ---------------------------------- | ----------------------------------- |
| 0xE         | [1110]        | $2^3 + 2^2 + 2^1 = 14$             | $-2^3 + 2^2 + 2^1 = -2$             |
| 0x0         | <u>[0000]</u> | <u>0</u>                           | <u>0</u>                            |
| 0x5         | <u>[0101]</u> | <u>$2^2 + 2^0 = 5$</u>             | <u>$2^2 + 2^0 = 5$</u>              |
| 0x8         | <u>[1000]</u> | <u>$2^3 = 8$</u>                   | <u>$-2^3 = -8$</u>                  |
| 0xD         | <u>[1101]</u> | <u>$2^3 + 2^2 + 2^0 = 13$</u>      | <u>$-2^3 +2^2 + 2^0 = -3$</u>       |
| 0xF         | <u>[1111]</u> | <u>$2^3 + 2^2 + 2^1 + 2^0= 15$</u> | <u>$-2^3 +2^2 + 2^1 + 2^0 = -1$</u> |

