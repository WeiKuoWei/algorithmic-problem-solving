import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static BigInteger maxProduct(int negNum, ArrayList<BigInteger> inputList, BigInteger product) {
        int n = inputList.size();
        // if there's only one number or if there's an even number of negatives
        if (n == 1 || negNum % 2 == 0) {
            return product;
        }

        // start checking from the left
        BigInteger productTemp = product;
        for (int i = 0; i < n; i++) {
            productTemp = productTemp.divide(inputList.get(i));
            // if encountering a negative number, change the number of negatives to even and break
            if (inputList.get(i).compareTo(BigInteger.ZERO) < 0) {
                break;
            }
        }

        // check from the right
        BigInteger newProduct = product.max(productTemp);
        productTemp = product;
        for (int i = n - 1; i > 0; i--) {
            productTemp = productTemp.divide(inputList.get(i));
            if (inputList.get(i).compareTo(BigInteger.ZERO) < 0) {
                break;
            }
        }

        return newProduct.max(productTemp);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        BigInteger currentMax = BigInteger.valueOf(Long.MIN_VALUE);
        BigInteger product = BigInteger.ONE;
        ArrayList<BigInteger> inputList = new ArrayList<>();

        int negNum = 0;
        for (int i = 0; i < n; i++) {
            BigInteger temp = scanner.nextBigInteger();

            // if temp == 0
            if (temp.equals(BigInteger.ZERO)) {
                // call maxProduct function to find the max product of the input list if not empty
                if (!inputList.isEmpty()) {
                    BigInteger newProduct = maxProduct(negNum, inputList, product);
                    currentMax = currentMax.max(newProduct);
                } else {
                    currentMax = currentMax.max(BigInteger.ZERO);
                }
                // reset the variables
                inputList.clear();
                product = BigInteger.ONE;
                negNum = 0;
            } else {
                inputList.add(temp);
                product = product.multiply(temp);

                if (temp.compareTo(BigInteger.ZERO) < 0) {
                    negNum++;
                }
            }
        }

        // if there are no 0s in the input list
        if (!inputList.isEmpty()) {
            BigInteger newProduct = maxProduct(negNum, inputList, product);
            currentMax = currentMax.max(newProduct);
        }

        System.out.println(currentMax);
    }
}


/*

javac Main.java
java Main


Example 1
Input:
4
5 -2 -10 -1
Output:
100

Example 2
Input:
1
-9
Output:
-9

Example 3
Input:
3 
0 0 0
Output:
0

Example 4
Input:
10
0 0 4 2 0 -4 2 -2 0 0
Output:
16

Example 5
Input:
8
-1 0 0 0 0 0 0 -1
Output:
0

Example 6
Input:
8
-1 0 0 5 0 2 -1 -2 
Output:
5

Example 7
4
1 1 1 1
Output:
1

*/