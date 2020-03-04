package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/* ó������ ����Ŭ�� ������ ��, Ȧ�������� �ȵȴٰ� ������ �غ���
 * �׸��� �̷����� �׷��ô��� ¦������Ŭ �ΰ��� �پ�������
 * ��ȸ�ϱⰡ �ָ��ߴ�.
 * �׷��� ������ �� �غ� ���, ������ �������ִ� ���� ���� �ٸ� ���̾�߱� ������
 * �׷����� ������ �� ������ ��ȸ�� �ϸ� �ڱ�� �ٸ� ���� �Է��� ���� ��,
 * ���������� �������踦 ������ ��, ���� ���� ������ false, �ٸ����� ���� ������ true ������� �����غ���
 * 
 *  1. �׷��ٸ� �׷����� ��� �����Ұ�����, ¦�� ��� ������ ������
 *  2. �׸��� ���ڷ� �޾Ƶ��� ������ ��� ���ڷ� ��ȯ �� ������
 *  
 *  1����.. ��.. �ƹ��ų� �ᵵ �� ���ϴ�. ť�� �����̵� ���� Ŭ�������� �־�ΰ�
 *  2���� ���ο� ���� ���� ������ �ѹ����� ��ȭ���ָ� ������� arraylist�� ����
 *  �׷� �Ƹ� visit�� �ذ��� �� �� �ϴ�.
 *  
 *  �̹� ���� ������ Ȯ���ϴ� �ſ��� set�̳� map�� ���� �����ٵ�, 200���ϱ� �׳��غ���
 *  �־��̾ 1+2+3+...+200 = 200*201/2 �󸶾ȵȴ�.
 * 
*/
public class Solution_D4_7988_�������_�̼��� {
	
	static class partner{
		int s1;
		int s2;
		public partner(int s1, int s2) {
			super();
			this.s1 = s1;
			this.s2 = s2;
		}
	}
	
	static ArrayList<Integer> graph[];
	static boolean[] visit;
	static int[] teamNum;
	static ArrayList<partner> partners = new ArrayList<>();
	static ArrayList<String> sameCheck= new ArrayList<String>();
	static int numbering;
	static int K;
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		for(int t = 1 ; t <= T; t++)
		{
			// �Է´ܰ�
			numbering = 0;
			partners.clear();
			sameCheck.clear();
			K = Integer.parseInt(br.readLine());
			
			graph = new ArrayList[K*K+1];
			for(int k = 0 ; k < K*K+1; k++)
				graph[k] = new ArrayList<Integer>();
			
			visit = new boolean[K*K+1];
			teamNum = new int[K*K+1];
			
			String s1, s2;
			int n1, n2;
			n1 = n2 = 0;
			
			for(int i = 0 ; i < K; i++)
			{
				st = new StringTokenizer(br.readLine());
				s1 = st.nextToken();		
				if(!sameCheck.contains(s1))
				{
					sameCheck.add(s1);
					n1 = numbering;
					numbering++;
				}
				else
				{
					n1 = sameCheck.indexOf(s1);
				}
				s2 = st.nextToken();
				if(!sameCheck.contains(s2))
				{
					sameCheck.add(s2);
					n2 = numbering;
					numbering++;
				}
				else
				{
					n2 = sameCheck.indexOf(s2);
				}
				graph[n1].add(n2);
				graph[n2].add(n1);
				partners.add(new partner(n1, n2));
			}
			
			// ������ ¦��, �׷��� ����
			
			for(int i = 0 ; i < sameCheck.size(); i++)
			{
				if(visit[i])
					continue;
				adjoinCheck(i);				
			}
			
			
			boolean isSame = false;
			for(int i = 0 ; i < partners.size(); i++)
			{
				if(teamNum[partners.get(i).s1] != teamNum[partners.get(i).s2])
					continue;
				isSame = true;
				break;
			}
			
			if(isSame)
				System.out.println("#" + t + " " + "No");
			else
				System.out.println("#" + t + " " + "Yes");
		}
	}
	
	static void adjoinCheck(int first)
	{
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(first);
		visit[first] = true;
		teamNum[first] = 0;
		
		while(!que.isEmpty())
		{
			int size = que.size();
			int curTeamNum = teamNum[que.peek()];
			while(size-->0)
			{
				int cur = que.poll();
				
				for(int i = 0 ; i < graph[cur].size(); i++)
				{
					int next = graph[cur].get(i);
					if(visit[next])
						continue;
					visit[next] = true;
					teamNum[next] = (curTeamNum+1)%2;
					que.add(next);
				}
				
			}
		}
		
		
		
	}
	
}












