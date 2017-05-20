class Main {
	public static void main(String[] args){
		java.math.BigInteger sum = java.math.BigInteger.valueOf(0);
		java.math.BigInteger zero = java.math.BigInteger.valueOf(0);
		java.util.Scanner sc = new java.util.Scanner(System.in);
		while (true){
			java.math.BigInteger bi = sc.nextBigInteger();
			if(bi.equals(zero)) break;
            sum = sum.add(bi);
		}
		sc.close();
		System.out.println(sum.toString());
	}
}
