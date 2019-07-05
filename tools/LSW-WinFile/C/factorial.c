int fac(n) {
	if (n == 0)
		return 1;
	else
		return fac(n-1) * n;
}
    
int main(int argc, char **argv) {
	return fac(10);
}