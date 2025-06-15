def day5fileParser():
    try:
        with open("data", "r") as f:
            lines = [line.strip() for line in f if line.strip()]
    except FileNotFoundError:
        return [], []

    if not lines:
        return [], []

    split_idx = 0
    while split_idx < len(lines) and '|' in lines[split_idx]:
        split_idx += 1

    rules = lines[:split_idx]
    updates = lines[split_idx:]
    return rules, updates


def partOne():
    rules, updates = day5fileParser()
    T = len(rules)
    X = [0] * T
    Y = [0] * T

    for i in range(T):
        s = rules[i]
        if '|' not in s:
            continue
        bar = s.find('|')
        X[i] = int(s[:bar])
        Y[i] = int(s[bar + 1:])

    sumMid = 0

    for line in updates:
        vals = line.split(',')
        pages = [int(v) for v in vals if v]
        if not pages:
            continue

        pos = {val: idx for idx, val in enumerate(pages)}

        ok = True
        for i in range(T):
            if X[i] in pos and Y[i] in pos and pos[X[i]] >= pos[Y[i]]:
                ok = False
                break

        if ok:
            sumMid += pages[len(pages) // 2]

    return sumMid


def partTwo():
    rules, updates = day5fileParser()

    return 0


if __name__ == "__main__":
    print(partOne())
    # print(partTwo())
