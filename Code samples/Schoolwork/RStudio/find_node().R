# Load data from 2 lists
o1 <- c(sample(1:10,sample(1:5,1)))
o2 <- c(sample(1:10,sample(1:5,1)))
o3 <- c(sample(1:10,sample(1:5,1)))
cluster_id_list <- list(o1,o2,o3)

temp1 <- sample(1:10,10)
temp2 <- sample(1:10,10)
test_node_list <- cbind(temp1, temp2)

# 0. Loop through the cluster list
# for (cluster in cluster_id_list) {
	# for (node in cluster) {
		# print (node)
	# }
  # print(cluster)
# }


# Get index
# i = cluster index
# j = node index
# for (i in 1:length(cluster_id_list)) {
	# print("Cluster:")
	# print(i)
	# for (j in 1:length(cluster_id_list[[i]])) {
		# print("Node:")
		# print(j)
	# }
# }


#==============================================================================

# 0. Initialize

coerce1 <- test_node_list 
coerce2 <- as.data.frame(coerce1, matrix(nrow = 10, ncol = 2)) # Make original test data into set of vectors

Node_Result <- 0 
Cluster_Result <- 0
DataFrame <- data.frame(matrix(ncol=0,nrow=0))

# 1. Algorithm: Search list 1 for value of list 2
for (a in coerce2) {
	for (b in 1:length(cluster_id_list)) {
		
		# 2. Make value of node to new DataFrame Node_Result column 1
		Node_Result <- (which(a %in% cluster_id_list[[b]]))
		
		# 3. Make value of cluster to new DataFrame Cluster_Result column 2
		Cluster_Result <- (b)
		
		# 4. Return DataFrame <- list(Node_Result, Cluster_Result)
		# DataFrame <- append(DataFrame, as.data.frame(cbind(Node_Result, Cluster_Result)))
		print(cbind(Cluster_Result,Node_Result))
	}
	cat("===============================")
	cat("\n")
}
cat("Print:")
cat("\n")
# print(DataFrame)
