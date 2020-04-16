//1 bg
package hw.bg;

/* ### ������ �κ� ###
 * 36�������� ����ߴ� ��
 * �ִ� ũ�Ⱑ 2^64 ���� ��
 * string reverse ǥ�� ���
 * �ʱ�ȭ ����� ���� �� 
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_J_3106_������ȯ_�̼��� {

	static final String[] numbering = new String[]  { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C",
			"D", "E", "F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		int A, B;
		String N;
		long before;
		String after;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		while (true) {
			st = new StringTokenizer(br.readLine());

			A = Integer.parseInt(st.nextToken());
			if (A == 0)
				break;
			N = st.nextToken();
			B = Integer.parseInt(st.nextToken());

			int len = N.length();
			long comp = 1;
			before = 0;
			// before�� A���� -> 10����ȭ
			for (int i = len - 1; i >= 0; i--) {
				try {
					before += Integer.parseInt(String.valueOf(N.charAt(i))) * comp;

				} catch (Exception e) {
					// System.out.println(String.valueOf(N.charAt(i)));
					for (int j = 0; j < numbering.length; j++) {
						// System.out.println(numbering[j]);
						if (numbering[j].equals(String.valueOf(N.charAt(i)))) {
							before += j * comp;
							// System.out.println("j: " +j);
						}
					}
				}
				comp *= A;
			}

			// before -> B����ȭ = after
			long quot = 0;
			long remain = 0;

			// System.out.println(before);

			after = "";
			while (true) {
				quot = before / B;
				remain = before % B;
				after += numbering[(int)remain];
				if (quot == 0)
					break;
				before = quot;
			}

			System.out.println(new StringBuffer(after).reverse().toString());

		}

	}

}
