import java.util.Calendar;
import java.util.Scanner;
public class Input_Date {
	public static void printCalendar(Calendar cal) {
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH);
		int day = cal.get(Calendar.DAY_OF_MONTH);
		System.out.print(year + "�� " + month + "�� " + day + "��\n");
	}
	public static void main(String[] Args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("��¥�� �Է��ϼ��� : ");
		String Date = scanner.next();//�Է¹ޱ�
		String s[] = Date.split("/"); // /�� �������� ������
		int year = Integer.valueOf(s[0]);
		int month = Integer.valueOf(s[1]);
		int day = Integer.valueOf(s[2]);
		Calendar Set_Date= Calendar.getInstance();
		Set_Date.clear();
		Set_Date.set(year,month,day); //��¥����
		printCalendar(Set_Date);
		scanner.close();
		
	}
}