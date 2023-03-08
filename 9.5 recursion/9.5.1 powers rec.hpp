double mpow(double x, int n){
    if (n == 0){
        return 1;
    }
    else {
        return x * mpow(x, n-1);
    }
}