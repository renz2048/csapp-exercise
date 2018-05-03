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

delete `=`

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