import sys
vocab = {}
reverse_vocab = {}

def evaluate(exp, vocab):
    for i in range(0, len(exp)-1, 2):
        if exp[i] not in vocab:
            return 'unknown'
        exp[i] = vocab[exp[i]]
    return eval("".join(exp[:-1]))



for line in sys.stdin.readlines():
    line = line.split()
    if line[0] == 'clear':
        vocab = {}
        reverse_vocab={}
    if line[0] == 'def':
        if line[2] in reverse_vocab:
            vocab.pop(reverse_vocab[line[2]])
        vocab[line[1]] = line[2]
        reverse_vocab[line[2]] = line[1]
    if line[0] == 'calc':
        val = evaluate(line[1:], vocab)
        if str(val) in reverse_vocab:
            val = reverse_vocab[str(val)]
        else:
            val = 'unknown'
        print(" ".join(line[1:]), val)