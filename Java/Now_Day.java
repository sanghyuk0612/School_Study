import java.util.Calendar;
public class Now_Day {
	public static void printCalendar(Calendar cal) {
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH) + 1;
		int day = cal.get(Calendar.DAY_OF_MONTH);
		int hourOfDay = cal.get(Calendar.HOUR_OF_DAY);
		int minute = cal.get(Calendar.MINUTE);
		int second = cal.get(Calendar.SECOND);
		System.out.print(year + "�� " + month + "�� " + day + "��\n");
		System.out.println(hourOfDay + "�� " + minute + "�� " + second + "��");
	}
	public static void main(String[] Args) {
		Calendar now = Calendar.getInstance();
		printCalendar(now);
	}
}
