long int double_as_long_int(double n){
  union {
    double d;
    long int i;
  } u;
  u.d = n;
  return u.i;
}
