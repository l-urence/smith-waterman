int max = n / sub;
int slice, j;
for (slice = 0; slice < 2 * max - 1; ++slice)
{
  int z = slice < max ? 0 : slice - max + 1;
  for (j = z; j <= slice - z; ++j)
  {
    int startI = j
    int startJ = (slice  - j) ;
     // ...
  }
  // ...
}
