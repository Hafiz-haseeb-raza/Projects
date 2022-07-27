import React, { useState,useEffect } from "react";
import Bloglist from "./Bloglist";
import useFetch from "./useFetch";
const Home = () => {
    const [name, setName]=useState("mario")
    const handleclick= ()=>{
        console.log("printing on console");
    }
    const handleclickAgain=(name)=>{
        setName("luigi ")
    }
  
    
    const [admin,setAdmin] = useState("haseeb")  
    
    const url="http://localhost:8000/blogs"
    const {blogs,isPending,error} = useFetch(url)
    const [blog,setBlog]=useState(blogs)
    const handleDelete= (id)=>{
        const newBlogs = blog.filter(blogs => blogs.id !== id);
        setBlog(newBlogs);
    }
    return ( 
        <div className="Home">
       
     
            <h1>Homepage</h1>
            <p>{name}</p>
            {error && <div>{error}</div>}
            {isPending && <div>Loading....</div>}
            {blogs &&< Bloglist blogs={blogs}  title="title" handleDelete={handleDelete} />}
            <button onClick={handleclick}> clicked</button>\
            <button onClick={()=>{
                handleclickAgain("haseeb");
            }}> Again</button>
            <button onClick={()=>setAdmin("choteMiyan") }>setstate  is used</button>
            <p>{admin}</p>
            <h3>
                <a href="/About">About us.</a>
            </h3>
        </div>
        
     )  ;
} 
 
export default Home;