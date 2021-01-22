pub fn map<T, S, F>(input: Vec<T>, mut function: F) -> Vec<S>
where
    F: FnMut(T) -> S,
{
    let mut v: Vec<S> = vec![];
    for i in input.into_iter() {
        v.push(function(i));
    }

    v
}
