import java.util.Calendar;
import java.util.Scanner;
public class Input_Date {
	public static void printCalendar(Calendar cal) {
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH);
		int day = cal.get(Calendar.DAY_OF_MONTH);
		System.out.print(year + "년 " + month + "월 " + day + "일\n");
	}
	public static void main(String[] Args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("날짜를 입력하세요 : ");
		String Date = scanner.next();//입력받기
		String s[] = Date.split("/"); // /를 기준으로 나눠줌
		int year = Integer.valueOf(s[0]);
		int month = Integer.valueOf(s[1]);
		int day = Integer.valueOf(s[2]);
		Calendar Set_Date= Calendar.getInstance();
		Set_Date.clear();
		Set_Date.set(year,month,day); //날짜설정
		printCalendar(Set_Date);
		scanner.close();
		
	}
}