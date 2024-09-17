export function enough(cap: number, on: number, wait: number): number {
    if (cap >= on + wait) {
        return 0;
    } else {
        return (on + wait) - cap;
    }
}