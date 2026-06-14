int prev = -1;
       for (int i = ind; i < cand.Length; i++){
           if (currSum + cand[i] > targ) break;
           if (prev == cand[i]) continue;
           currComb.Add(cand[i]);
           findComb(cand, targ, currSum + cand[i], currComb, i + 1);
           currComb.RemoveAt(currComb.Count - 1);
           prev = cand[i];
       }