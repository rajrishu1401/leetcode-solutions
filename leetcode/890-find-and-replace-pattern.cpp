for (const word of words) {
    if (isIsomorphic(word, pattern)) { //solve this first
        res.push(word);
    }
}

return res;