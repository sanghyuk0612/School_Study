import java.util.Scanner;
public class Song {
	//필드 변수 선언 부분
	String song_name; 
	String singer;
	int year;
	String country;
	public Song() {
		//기본생성자 작성
		song_name = "아무노래";
		singer = "지코";
		year = 1987;
		country = "한국";
	}
	public Song(String s_name, String singer1, int year1, String country1) {
		//매개변수들을 받아서 생성자에 대입
		song_name = s_name;
		singer = singer1;
		year = year1;
		country = country1;
	}

	//메소드 정의
	public void show() {
		//변수들을 받아서 출력
		System.out.println("Song 정보 : "+year+"년, "+country+" 국적의 "+singer+"가 부른 \""+song_name+"\"");
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		//생성자 생성
		
		System.out.print("노래제목 가수 발표년도 국적 순으로 적어주세요\n");
		//입력받는 부분
		String S_name = scanner.nextLine();
		String singer = scanner.nextLine();
		int year = scanner.nextInt();
		String country = scanner.next();
		//생성자 선언
		Song info = new Song(S_name, singer , year , country);
		Song info2 = new Song();
		//출력메소드 호출
		info.show();
		info2.show();
		scanner.close();
	}
}


