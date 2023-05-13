import java.util.Scanner;
public class Spin_Stiring {
	public static void main(String[] Args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("입력) ");
		String s = scanner.next();
		int n = scanner.nextInt();
		if (n>0) {
			for (int i = 0;i+n<=s.length();i=i+n) {
				String t1 = s.substring(0,n); //0부터 n까지 슬라이싱
				String t2 = s.substring(n); //n부터 끝까지 슬라이싱
				t2 = t2.concat(t1); //반대로 이어붙임
				s = t2;
				System.out.println(s);
			}
		}
		else if(n<0) {
			n = -n;
			for (int i = 0; i+n<=s.length();i=i+n) {
				String t1 = s.substring(0,s.length()-n);//0부터 길이-n까지 슬라이싱
				String t2 = s.substring(s.length()-n);//길이-n부터 끝까지 슬라이싱
				t2 = t2.concat(t1); //반대로 이어붙임
				s = t2; //다시대입
				System.out.println(s);
			}
		}
		else {
			System.out.println("종료함");
		}
		
		scanner.close();
	}
}
