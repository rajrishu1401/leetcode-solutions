for (int idx : idxMap[arr[i]]) {
         if (m != i && !visited[m]) {
              q.push(m);
              visited[m] = true;
           }
  }
 idxMap[arr[i]].clear();  //important