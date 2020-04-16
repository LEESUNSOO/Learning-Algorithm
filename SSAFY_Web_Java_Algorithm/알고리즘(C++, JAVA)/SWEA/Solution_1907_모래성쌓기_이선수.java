package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 0030~0150(1���õ�) + ~ 0230 = 2H
// 7�� -> 2��, 262144kbytes => 256MB
// ���깮������? �װŶ� ����Ѱ� ������
// ���̰� �ִٸ� ����? 1000������°��̴�.
// �ĵ��� ĥ������ �𷡼��� �ֺ� ������ ������������ϴµ�,
// �ĵ��� �ѹ� ĥ������ �ִ�������� �ּ� 1,000,000(��������)�� ������ �̷������Ѵ�. 
// ���Ҿ� �� ���긶�� �ȹ����� �˻��ϸ� *8, �ĵ� ������ �ĵ� 1���̴�.

// ���� Ŭ�����θ� �ؼ� ���� ��ȸ�� �ϴ� �ð��ʰ��� ����.
// add�� �ϴ� ������������ �������� ���������� �ȹ������� �� �� �ִµ�, �̰� �ܼ�ȭ���Ѻ���.


public class Solution_1907_�𷡼��ױ�_�̼���2 {
	
	static class pos{
		int y;
		int x;
		
		pos(int y, int x)
		{
			this.y = y;
			this.x = x;
		}
	}
	
	static int[][] dir = new int[][] {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}; // i%2 ==0 �����̵� , 1�� �����̵�
	static int N, M;
	static int[][] nadj;
	static int[][] map;
	static boolean[][] visit;
	static Queue<pos> que = new LinkedList<>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++)
		{
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			map = new int[N][M];
			nadj = new int[N][M];
			visit = new boolean[N][M];
			
			for(int i = 0 ; i < N ; i++)
			{
				String s = br.readLine();
				for(int j = 0 ; j < M; j++)
				{
					char c = s.charAt(j);
					
					if(Character.isDigit(c))
					{
						map[i][j] = c - '0';
					}
					else
					{
						map[i][j] = -1;
					}
				}
			}
			adjoinCheck();
			System.out.println("#" + t + " " + destroy());
		}
		
	}
	
	static int destroy()
	{
		int cnt = 0;
		int size = 0;
		pos cur;
		int curY, curX;
		int ny, nx;
		while(!que.isEmpty())
		{
			size = que.size();
			
			while(size-->0)
			{
				cur = que.poll(); // ������ �ֵ�
				curY = cur.y;
				curX = cur.x;
				
				//�����
				/*
				 * map[curY][curX] = -1; for(int i = 0 ; i < N;i++)
				 * System.out.println(Arrays.toString(map[i])); System.out.println();
				 */
				
				for(int k = 0 ; k < 8 ; k ++)
				{
					ny = curY+dir[k][0];
					nx = curX+dir[k][1];
					
					if(ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == -1)
						continue;
					nadj[ny][nx]++;
					if(map[ny][nx] <= nadj[ny][nx]) // �� ó�� �μ��� �ֵ�
					{
						visit[ny][nx] = true;
						que.add(new pos(ny,nx));
					}
				}
			}
			cnt++;
		}
		
		
		return cnt;
	}
	
	static void adjoinCheck()
	{
		int ny, nx;
		for(int i = 0 ; i < N; i++)
		{
			for(int j = 0 ; j < M ; j++)
			{
				if(map[i][j] == -1 || map[i][j] == 9)
					continue;
				
				for(int k = 0 ; k < 8 ; k ++)
				{
					ny = i+dir[k][0];
					nx = j+dir[k][1];
					
					if(ny < 0 || nx < 0 || ny >= N || nx >= M )
						continue;
					
					if(map[ny][nx] == -1)
						nadj[i][j]++;
				}
				
				if(map[i][j] <= nadj[i][j]) // �� ó�� �μ��� �ֵ�
				{
					visit[i][j] = true;
					que.add(new pos(i,j));
				}
			}
		}		
	}	
}










