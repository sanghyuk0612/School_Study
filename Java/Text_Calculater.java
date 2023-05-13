import java.util.Scanner;
import java.util.Vector;
import java.util.StringTokenizer;
public class Calculater {
	public static void main(String[] Args) {
		int temp = 1;
		int j = 1;
		Scanner scanner = new Scanner(System.in);
		System.out.print("식을 입력하세요 : ");
		String s = scanner.nextLine();
		Vector<Integer> v = new Vector<Integer>(); //Integer형 Vector 선언 
		StringTokenizer st = new StringTokenizer(s,"+-"); //+-를 기준으로 토큰화한후 st에 넣음
		while (st.hasMoreTokens()) {
			v.add(Integer.valueOf(st.nextToken()));
		}
		int op;
		int result = v.get(0); //첫번재 요소 대입
		for (int i=0;i<s.length();i++) {
			char ch = s.charAt(i); //첫번째 글자 대입
			switch(ch) {
			case '+': //+면 더해줌
				if (temp==1){//부호가 이어서 나왔으면 프로그램종료
					System.out.println("프로그램종료");
					System.exit(0);
					break;
				}
				op = v.get(j++);
				result = result+op;
				temp = 1;//부호가 이어서 나오는지 확인하기위해 1로 바꿔줌
				break;
			case '-':
				if (temp==1){ 
					System.out.println("프로그램종료");
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
		System.out.println("결과는"+result+"입니다");
		scanner.close();
	}
}
