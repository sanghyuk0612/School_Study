import java.util.Scanner;
public class Spin_Stiring {
	public static void main(String[] Args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("�Է�) ");
		String s = scanner.next();
		int n = scanner.nextInt();
		if (n>0) {
			for (int i = 0;i+n<=s.length();i=i+n) {
				String t1 = s.substring(0,n); //0���� n���� �����̽�
				String t2 = s.substring(n); //n���� ������ �����̽�
				t2 = t2.concat(t1); //�ݴ�� �̾����
				s = t2;
				System.out.println(s);
			}
		}
		else if(n<0) {
			n = -n;
			for (int i = 0; i+n<=s.length();i=i+n) {
				String t1 = s.substring(0,s.length()-n);//0���� ����-n���� �����̽�
				String t2 = s.substring(s.length()-n);//����-n���� ������ �����̽�
				t2 = t2.concat(t1); //�ݴ�� �̾����
				s = t2; //�ٽô���
				System.out.println(s);
			}
		}
		else {
			System.out.println("������");
		}
		
		scanner.close();
	}
}
