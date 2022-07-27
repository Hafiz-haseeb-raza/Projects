
import useFetch from "./useFetch";
const Bloglist = ({blogs,title,handleDelete}) => {
    //const blogs=props.blogs;
    //const title =props.title;
    //<button onClick={()=>handleDelete(Bloglist.id)} >Delete this</button>
    
    return (
        <div className="bloglist">
            {blogs.map((Bloglist) => (
                <div className="blog-preview" key={blogs.id}>
                    <h2>{Bloglist.name} is the name</h2>
                    <p>{Bloglist.body} is its body</p>
                    
                </div>
            ))}
        </div>
    );
}

export default Bloglist;