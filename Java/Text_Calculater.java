import java.util.Scanner;
import java.util.Vector;
import java.util.StringTokenizer;
public class Calculater {
	public static void main(String[] Args) {
		int temp = 1;
		int j = 1;
		Scanner scanner = new Scanner(System.in);
		System.out.print("���� �Է��ϼ��� : ");
		String s = scanner.nextLine();
		Vector<Integer> v = new Vector<Integer>(); //Integer�� Vector ���� 
		StringTokenizer st = new StringTokenizer(s,"+-"); //+-�� �������� ��ūȭ���� st�� ����
		while (st.hasMoreTokens()) {
			v.add(Integer.valueOf(st.nextToken()));
		}
		int op;
		int result = v.get(0); //ù���� ��� ����
		for (int i=0;i<s.length();i++) {
			char ch = s.charAt(i); //ù��° ���� ����
			switch(ch) {
			case '+': //+�� ������
				if (temp==1){//��ȣ�� �̾ �������� ���α׷�����
					System.out.println("���α׷�����");
					System.exit(0);
					break;
				}
				op = v.get(j++);
				result = result+op;
				temp = 1;//��ȣ�� �̾ �������� Ȯ���ϱ����� 1�� �ٲ���
				break;
			case '-':
				if (temp==1){ 
					System.out.println("���α׷�����");
					System.exit(0);
					break;
				}
				op = v.get(j++);
				result = result-op;
				temp = 1;
				break;
			default: 
				temp =0;
				break;
			}
		}	
		System.out.println("�����"+result+"�Դϴ�");
		scanner.close();
	}
}
