/*

template:

    void bfs(起始点){
        
        将起始点放入队列中
        起始点标记为访问
        
        while(如果队列不为空){

            访问队列头元素x
            删除头元素

            for(x的所有相邻点){

                if(该点未被访问过并且合法){

                    将该元素放入队列末尾
                }
            }
        }
        队列结束，bfs结束
    }
*/