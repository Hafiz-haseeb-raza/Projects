import { useEffect, useState } from "react";

const useFetch = (url) => {
    const [blogs, setBlogs] = useState(null)
    const [error, setError] = useState(null)
    const [isPending, setisPending] = useState(true)
    useEffect(() => {
        setTimeout(() => {
            fetch(url)
                .then(res => {
                    if (res.ok == false)
                        throw Error('couldnt connect to the server')
                    return res.json();
                })
                .then(data => {
                    setisPending(false)
                    setBlogs(data);
                })
                .catch(err => {
                    setError(err.message)
                    setisPending(false)
                })
        }, 3000);

    }, [])
    return { blogs, isPending, error }
}

export default useFetch