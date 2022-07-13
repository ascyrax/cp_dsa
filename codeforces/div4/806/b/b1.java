import java.util.HashSet;
import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

public class b1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    for (int ii = 0; ii < t; ii++) {
      int n = sc.nextInt();
      String s = sc.next();
      int lens = n;
      Set<Character> st = new HashSet<>();
      for (int i = 0; i < lens; i++) {
        st.add(s.charAt(i));
      }
      int ans = lens + st.size();
      System.out.println(ans);
    }
    sc.close();
  }
}