function possibleStringCount(word: string): number {
    if (!word || word.length === 0) {
        return 0;
    }

    let count = 1;

    for(let i = 1; i < word.length; i++) {
        if(word[i] == word[i-1]) {
            ++count;
        }
    }

    return count;
};