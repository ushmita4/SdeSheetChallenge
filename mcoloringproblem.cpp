bool isCorrect(vector<vector<int>> &mat, int cur, vector<int> &color, int col)
{
	for (int i = 0; i < mat.size(); ++i)
	{
		if(mat[cur][i] && color[i] == col)
		{
			return false;
		}
	}

	return true;
}

bool graphCol(vector<vector<int>> &mat, int m, int cur, vector<int> &color)
{
	if(cur == mat.size())
	{
		return true;
	}

	for (int j = 1; j <= m; ++j)
	{
		if(isCorrect(mat, cur, color, j))
		{
			color[cur] = j;
			if(graphCol(mat, m, cur+1, color))
			{
				return true;
			}
			color[cur] = 0;
		}
	}

	return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
	int v = mat.size();
	vector<int> color(v, 0);
	if(graphCol(mat, m, 0, color))
	{
		return "YES";
	}
	else
	{
		return "NO";
	}
}
