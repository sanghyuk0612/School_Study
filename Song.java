import java.util.Scanner;
public class Song {
	//�ʵ� ���� ���� �κ�
	String song_name; 
	String singer;
	int year;
	String country;
	public Song() {
		//�⺻������ �ۼ�
		song_name = "�ƹ��뷡";
		singer = "����";
		year = 1987;
		country = "�ѱ�";
	}
	public Song(String s_name, String singer1, int year1, String country1) {
		//�Ű��������� �޾Ƽ� �����ڿ� ����
		song_name = s_name;
		singer = singer1;
		year = year1;
		country = country1;
	}

	//�޼ҵ� ����
	public void show() {
		//�������� �޾Ƽ� ���
		System.out.println("Song ���� : "+year+"��, "+country+" ������ "+singer+"�� �θ� \""+song_name+"\"");
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		//������ ����
		
		System.out.print("�뷡���� ���� ��ǥ�⵵ ���� ������ �����ּ���\n");
		//�Է¹޴� �κ�
		String S_name = scanner.nextLine();
		String singer = scanner.nextLine();
		int year = scanner.nextInt();
		String country = scanner.next();
		//������ ����
		Song info = new Song(S_name, singer , year , country);
		Song info2 = new Song();
		//��¸޼ҵ� ȣ��
		info.show();
		info2.show();
		scanner.close();
	}
}


