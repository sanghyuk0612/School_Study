import java.util.InputMismatchException;
import java.util.Scanner;
public class Calculate {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scanner = new Scanner(System.in); // scanner 생성자 생성
		char ch = ' ';
		int N1 = 1; //각각 변수 값 초기화
		int N2 = 2;
		String s;
		System.out.println("정수 사칙연산 정수 순서대로 입력해주세요.");
		while(true) { //예외적인 값이 입력받는다면 정상적인 값을 입력받을 때까지 무한반복
			try {
				N1 = scanner.nextInt();
				s = scanner.next();
				N2 = scanner.nextInt();
				ch = s.charAt(0); //입력받은 String성분을 char로 변경
				break;
			}
			catch(InputMismatchException e) {
				System.out.print("error : 정수 사칙연산 정수 순서대로 입력해주세요.\n");
				// 에러메세지 출력 
				scanner.nextLine();
				//입력받은 값 초기화
			}
		}
		int result = 0; // 결괏값 초기화
		while (ch != '=') { // '='을 입력받는다면 프로그램 종료
			switch(ch) { 
			case'-': //case 사칙연산 부분이 '-'인 경우
				result = N1-N2; //결과는 N1-N2
				System.out.println("결과는 "+result+"입니다.");
				break;
			case'+': //case 사칙연산 부분이 '+'인 경우
				result = N1+N2; //결과는 N1+N2
				System.out.println("결과는 "+result+"입니다.");
				break;
			case'*': //case 사칙연산 부분이 '*'인경우
				result = N1*N2; //결과는 N1* N2
				System.out.println("결과는 "+result+"입니다.");
				break;
			case'%': // case 사칙연산 부분이 '%'인 경우 
				result = N1%N2; // 결과는 N1 % N2
				System.out.println("결과는 "+result+"입니다.");
				break;
			case'/': // case 사칙연산 부분이 '/' 인 경우
				try {
					result = N1/N2; // 결과값은 N1/N2
				}
				catch(ArithmeticException e) { // 만약 N2가 0이라면 발생되는 에러를 잡음
					System.out.println("error : 0으로 나눌수는 없습니다."); // 에러메세지 출력
					break;
				}
				System.out.println("결과는 "+result+"입니다."); // 에러가 나오지않았다면 결괏값 출력
				break;
			}
			while(true) {
				try {
					N1 = scanner.nextInt();
					s = scanner.next();
					N2 = scanner.nextInt();
					ch = s.charAt(0);
					break;
				}
				catch(InputMismatchException e) {
					System.out.print("error : 정수 사칙연산 정수 순서대로 입력해주세요.\n");
					scanner.nextLine();
				}
			
			}
			
		}
		System.out.print("프로그램 종료"); // 사칙연산 부분 '='으로 받았을경우 메세지와 함께 프로그램 종료
		scanner.close();
	}
}
