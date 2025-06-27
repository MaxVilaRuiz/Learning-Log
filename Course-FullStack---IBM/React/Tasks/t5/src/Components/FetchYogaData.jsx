import React from 'react'
import useFetch from './UseFetch';

const FetchYogaData = () => {
    const [data] = useFetch('https://api.npoint.io/4459a9a10e43812e1152');
    console.log(data);

    return (
        <>
        <h1 className='useFetch_heading'>Use Fetch Custom Hook</h1>
        <ul className='list_data_main'>
          {data && data.map((e, index) => (
            <li key={index} className='list_data'>
              <h3>{e.name}</h3>
              <p><strong>Importance: </strong>{e.importance}</p>
              <p><strong>Benefits: </strong>{e.benefits}</p>
              <p><strong>Time to eat: </strong>{e.best_time_to_intake}</p>
            </li>
          ))}
        </ul>
      </>
    )
}

export default FetchYogaData;