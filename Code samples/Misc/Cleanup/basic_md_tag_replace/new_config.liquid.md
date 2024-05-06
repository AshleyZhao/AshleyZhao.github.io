---
created: "2020-11-09 11:46:13 -0500"
title: "Configuring pipeline nodes"
---
{{site.data.keyword.attributedefs}}

# Configuring pipeline nodes

Configure the nodes of your pipeline to specify inputs and to create outputs as part of your pipeline.
{: .shortdesc}

## Specifying the workspace scope

By default, the scope for a pipeline is the project that contains the pipeline. You can explicitly specify a scope other than the default, to locate an asset used in the pipeline. The scope is the project, catalog, or space that contains the asset. From the user interface, you can browse for the scope.

{% if site.prodkey == "icpd" or site.prodkey == "opx" %}
In a notebook, specify the scope as part of the path to an asset, as follows:

```bash
[cpd://]/(projects|spaces|catalogs)/<scope-id>/<resource-type>/<resource-ID>
```
{: .codeblock}

Where:

- **context** is the URL for the cluster or server where you access {{site.data.keyword.data}}.
- **scope** is the project, space, or catalog that contains the resource.
- **resource** can be identified with the name or ID.

{% endif %}

## Changing the input mode

When you are configuring a node, you can specify any resources that include data and notebooks in various ways. Such as directly entering a name or ID, browsing for an asset, or by using the output from a prior node in the pipeline to populate a field. To see what options are available for a field, click the input icon for the field. Depending on the context, options can include:

- Select resource: use the asset browser to find an asset such as a data file.
- Assign pipeline parameter: assign a value by using a variable configured with a pipeline parameter. For more information, see [Configuring global objects](ml-orchestration-flow-param.html).
- Select from another node: use the output from a node earlier in the pipeline as the value for this field.
- Enter the expression: enter code to assign values or identify resources. For more information, see [Coding elements](ml-orchestration-expr-builder.html).

## Pipeline nodes and parameters

Configure the following types of pipeline nodes:

- [Copy nodes](#copy)
- [Send nodes](#send)
- [Create nodes](#create)
- [Wait](#wait)
- [Control nodes](#control)
- [Update nodes](#update)
- [Delete nodes](#delete)
- [Run nodes](#run)
- [Configure nodes](#configure)

## Copy nodes
{: #copy}

Use Copy nodes to add assets to your pipeline or to export pipeline assets.

Copy selected assets from a project or space to a nonempty space. You can copy these assets to a space:

- AutoAI experiment
- Code package job
- Connection
- {{ site.data.keyword.data_refinery }} flow
- {{ site.data.keyword.data_refinery }} job
- Data asset
{% if site.prodkey=="cloud" %}
- {{ site.data.keyword.datastage }} job
{% endif %}
- Deployment job
- Environment
- Function
- Job
- Model
- Notebook
- Notebook job
- {{ site.data.keyword.pipeline }} job
- Script
- Script job
- {{ site.data.keyword.spss_modeler }} job

#### Input parameters

|Parameter|Description|
|---|---|
|Source assets |Browse or search for the source asset to add to the list. You can also specify an asset with a pipeline parameter, with the output of another node, or by entering the asset ID|
|Target|Browse or search for the target space|
|Copy mode|Choose how to handle a case where the flow tries to copy an asset and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|


#### Output parameters

|Parameter|Description|
|---|---|
|Output assets |List of copied assets|

### Copy assets
Export selected assets from the scope, for example, a project or deployment space. The operation exports all the assets by default. You can limit asset selection by building a list of resources to export.

#### Input parameters

|Parameter|Description|
|---|---|
|Assets |Choose **Scope** to export all exportable items or choose **List** to create a list of specific items to export|
|Source project or space |Name of project or space that contains the assets to export|
|Exported file |File location for storing the export file|
|Creation mode (optional)|Choose how to handle a case where the flow tries to create an asset and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|

#### Output parameters

|Parameter|Description|
|---|---|
|Exported file|Path to exported file|

**Notes:**

- If you export a project that contains a notebook, the latest version of the notebook is included in the export file. If the Pipeline with the **Run notebook job** node was configured to use a different notebook version other than the latest version, the exported Pipeline is automatically reconfigured to use the latest version when imported. This might produce unexpected results or require some reconfiguration after the import.
- If assets are self-contained in the exported project, they are retained when you import a new project. Otherwise, some configuration might be required following an import of exported assets.

### Export assets
Import assets from a ZIP file that contains exported assets.

#### Input parameters

|Parameter|Description|
|---|---|
|Path to import target |Browse or search for the assets to import|
|Archive file to import |Specify the path to a ZIP file or archive|

**Notes:** After you import a file, paths and references to the imported assets are updated, following these rules:

- References to assets from the exported project or space are updated in the new project or space after the import.
- If assets from the exported project refer to external assets (included in a different project), the reference to the external asset will persist after the import.
- If the external asset no longer exists, the parameter is replaced with an empty value and you must reconfigure the field to point to a valid asset.

### Import assets
{% if site.prodkey == "icpd" or site.prodkey == "opx" %}

## Send nodes
{: #send}

Communicate with other users about events in your pipeline.

Send email to notify recipients about an event in a pipeline.

{% render "note.html", type: "note", text: "To provide a secure way to transmit information about pipeline events, email addresses and content must be uploaded from files rather than entered directly in the pipeline form." %}

#### Prerequisites

- Users must configure their user preferences to receive emails.
- SMTP service must be configured on the {{site.data.keyword.data}} cluster. For more information, see {% if site.prodkey == "icpd" %}[Enabling email notifications](../../cpd/admin/post-install-smpt-config.html){% else if site.prodkey == "opx" %}[Enabling email notifications]({{ site.data.keyword.cpddocs }}/cpd/admin/post-install-smpt-config.html). {% endif %}Note: you must configure an admin for SMTP before you complete the mail setup. 

#### Input parameters

|Parameter|Description|
|---|---|
|Recipients email addresses file| Connect to a .txt file that contains the email addresses for the recipient with addresses that are separated with commas. Enter in prefix@domain format. For compliance with data management protocols, the recommendation is to use group emails (functional addresses) instead of personal addresses.|
|Email subject| Enter the title for the message|
|Predefined mail body template text file| Connect to a text file that contains the body of the message for the email. The message can be in plain text or HTML.|
|Attachments (optional) | Send one or more attachments in your email. |
|Compress attachments (optional) | Compress the attachments into a compressed file. This option is true by default.</br>**Note:** If it is false, then only the first 4 attachments are included in the email and the rest of the attachments are dropped. |
|Body template variables|Use variables to insert items such as user name, job name, or other job details into the message body. For each variable, enter the key (variable name) by using the format \{\{VAR\}\}, choose a type, optionally define the variable with an expression, and add to the list|
|Error policy (optional)| Optionally, override the default error policy for the node|


#### Output parameters

|Parameter|Description|
|---|---|
|Execution status| Returns a value of: Completed, Completed with warnings, Completed with errors, Failed, Canceled, or Configuration error|
|Status message| Message associated with the status|

### Send email
{% endif %}

## Create nodes
{: #create}

Configure the nodes for creating assets in your pipeline.

Use this node to train an [AutoAI classification or regression experiment](autoai-overview.html) and generate model-candidate pipelines.

#### Input parameters

|Parameter|Description|
|---|---|
|AutoAI experiment name|Name of the new experiment|
|Scope|A project or a space, where the experiment is going to be created|
|Prediction type|The type of model for the following data: binary, classification, or regression|
|Prediction column (label)|The prediction column name|
|Positive class (optional)|Specify a positive class for a binary classification experiment|
|Training data split ratio (optional)|The percentage of data to hold back from training and use to test the pipelines(float: 0.0 - 1.0)|
|Algorithms to include (optional)|Limit the list of estimators to be used (the list depends on the learning type)|
|Algorithms to use|Specify the list of estimators to be used (the list depends on the learning type)|
|Optimize metric (optional)| The metric used for model ranking|
|Hardware specification (optional)|Specify a hardware specification for the experiment|
|AutoAI experiment description|Description of the experiment|
|AutoAI experiment tags (optional)|Tags to identify the experiment|
|Creation mode (optional)|Choose how to handle a case where the pipeline tries to create an experiment and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|


#### Output parameters

|Parameter|Description|
|---|---|
|AutoAI experiment|Path to the saved model|

### Create AutoAI experiment
Use this node to train an [AutoAI time series experiment](autoai-overview.html) and generate model-candidate pipelines.

#### Input parameters

|Parameter|Description|
|---|---|
|AutoAI time series experiment name|Name of the new experiment|
|Scope|A project or a space, where the pipeline is going to be created|
|Prediction columns (label)|The name of one or more prediction columns|
|Date/time column (optional)|Name of date/time column|
|Leverage future values of supporting features|Choose "True" to enable the consideration for supporting (exogenous) features to improve the prediction. For example, include a temperature feature for predicting ice cream sales.|
|Supporting features (optional)|Choose supporting features and add to list|
|Imputation method (optional)|Choose a technique for imputing missing values in a data set|
|Imputation threshold (optional)|Specify an higher threshold for percentage of missing values to supply with the specified imputation method. If the threshold is exceeded, the experiment fails. For example, if you specify that 10% of values can be imputed, and the data set is missing 15% of values, the experiment fails.|
|Fill type|Specify how the specified imputation method fill null values. Choose to supply a mean of all values, and median of all values, or specify a fill value.|
|Fill value (optional)|If you selected to sepcify a value for replacing null values, enter the value in this field.|
|Final training data set|Choose whether to train final pipelines with just the training data or with training data and holdout data. If you choose training data, the generated notebook includes a cell for retrieving holdout data|
|Holdout size (optional)|If you are splitting training data into training and holdout data, specify a percentage of the training data to reserve as holdout data for validating the pipelines. Holdout data does not exceed a third of the data.|
|Number of backtests (optional)|Customize the backtests to cross-validate your time series experiment|
|Gap length (optional)|Adjust the number of time points between the training data set and validation data set for each backtest. When the parameter value is non-zero, the time series values in the gap is not used to train the experiment or evaluate the current backtest.|
|Lookback window (optional)|A parameter that indicates how many previous time series values are used to predict the current time point.|
|Forecast window (optional)|The range that you want to predict based on the data in the lookback window.|
|Algorithms to include (optional)|Limit the list of estimators to be used (the list depends on the learning type)|
|Pipelines to complete|Optionally adjust the number of pipelines to create. More pipelines increase training time and resources.|
|Hardware specification (optional)|Specify a hardware specification for the experiment|
|AutoAI time series experiment description (optional)|Description of the experiment|
|AutoAI experiment tags (optional)|Tags to identify the experiment|
|Creation mode (optional)|Choose how to handle a case where the pipeline tries to create an experiment and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|

#### Output parameters

|Parameter|Description|
|---|---|
|AutoAI time series experiment|Path to the saved model|

### Create AutoAI time series experiment
Use this node to create a batch deployment for a machine learning model.

#### Input parameters

|Parameter|Description|
|---|---|
|ML asset|Name or ID of the machine learning asset to deploy|
|New deployment name (optional)|Name of the new job, with optional description and tags|
|Creation mode (optional)|How to handle a case where the pipeline tries to create a job and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|
|New deployment description (optional)| Description of the deployment|
|New deployment tags (optional)| Tags to identify the deployment|
|Hardware specification (optional)|Specify a hardware specification for the job|


#### Output parameters

|Parameter|Description|
|---|---|
|New deployment| Path of the newly created deployment|

### Create batch deployment
Use this node to create a data asset.

#### Input parameters

|Parameter|Description|
|---|---|
|File |Path to file in a file storage|
|Target scope| Path to the target space or project|
|Name (optional)|Name of the data source with optional description, country of origin, and tags|
|Description (optional)| Description for the asset|
|Origin country (optional)|Origin country for data regulations|
|Tags (optional)| Tags to identify assets|
|Creation mode|How to handle a case where the pipeline tries to create a job and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|

#### Output parameters

|Parameter|Description|
|---|---|
|Data asset|The newly created data asset|

### Create data asset
Use this node to create and configure a space that you can use to organize and create deployments.

#### Input parameters

|Parameter|Description|
|---|---|
|New space name|Name of the new space with optional description and tags|
|New space tags (optional)| Tags to identify the space|
{% if site.prodkey == "cloud" or site.prodkey == "wx" %}|New space COS instance CRN |CRN of the COS service instance|
|New space WML instance CRN (optional)|CRN of the {{ site.data.keyword.wml }} service instance|{%- endif %}
|Creation mode (optional)|How to handle a case where the pipeline tries to create a space and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|
|Space description (optional)|Description of the space|

#### Output parameters

|Parameter|Description|
|---|---|
|Space|Path of the newly created space|

### Create deployment space
Use this node to create an online deployment where you can submit test data directly to a web service REST API endpoint.

#### Input parameters

|Parameter|Description|
|---|---|
|ML asset|Name or ID of the machine learning asset to deploy|
|New deployment name (optional)|Name of the new job, with optional description and tags|
|Creation mode (optional)|How to handle a case where the pipeline tries to create a job and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|
|New deployment description (optional)| Description of the deployment|
|New deployment tags (optional)| Tags to identify the deployment|
|Hardware specification (optional)|Specify a hardware specification for the job|

#### Output parameters

|Parameter|Description|
|---|---|
|New deployment| Path of the newly created deployment|

### Create online deployment
{% comment %}

### Create R-Shiny Deployment (in-progress)

This node creates an R-Shiny application deployment

Inputs

    name (String) - Name of the new deployment
    description (String, optional) - Description of the new deployment
    space-id (Space) - ID of the deployment space
    asset-id (RShinyVersion) - RShiny asset version to be deployed
    hardware-spec (HardwareSpecVersion) - the hardware specification asset version
    authentication (String, enum) - anyone_with_url, any_valid_cpd_user, members_of_deployment_space
    tags (List[String], optional) - deployment tags

Outputs

    deployment-id (Deployment) - ID of the newly created deployment

#### Output parameters

|Parameter|Description|
|---|---|
|Pipeline ID|ID of the newly created pipeline|


{% endcomment %}

## Wait
{: #wait}

Use nodes to pause a pipeline until an asset is available in the location that is specified in the path.

Use this node to wait until all results from the previous nodes in the pipeline are available so the pipeline can continue.

This node takes no inputs and produces no output. When the results are all available, the pipeline continues automatically.

### Wait for all results
Use this node to wait until any result from the previous nodes in the pipeline is available so the pipeline can continue. Run the downstream nodes as soon as any of the upstream conditions are met.

This node takes no inputs and produces no output. When any results are available, the pipeline continues automatically.

### Wait for any result
Wait for an asset to be created or updated in the location that is specified in the path from a job or process earlier in the pipeline. Specify a timeout length to wait for the condition to be met. If 00:00:00 is the specified timeout length, the flow waits indefinitely.

#### Input parameters

|Parameter|Description|
|---|---|
|File location|Specify the location in the asset browser where the asset resides. Use the format `data_asset/filename` where the path is relative to the root. The file must exist and be in the location you specify or the node fails with an error.  {% comment %}Use the format `bucket_name/file_path_in_bucket`. {% endcomment %}|
|Wait mode| By default the mode is for the file to appear. You can change to waiting for the file to disappear|
|Timeout length (optional)|Specify the length of time to wait before you proceed with the pipeline. Use the format `hh:mm:ss`|
|Error policy (optional)| See [Handling errors](ml-orchestration-errors.html)|

#### Output parameters

|Parameter|Description|
|---|---|
|Return value|Return value from the node|
|Execution status| Returns a value of: Completed, Completed with warnings, Completed with errors, Failed, or Canceled|
|Status message| Message associated with the status|

### Wait for file
## Control nodes
{: #control}

Control the pipeline by adding error handling and logic.

Loops are a node in a Pipeline that operates like a coded loop.

The two types of loops are parallel and sequential.

You can use loops when the number of iterations for an operation is dynamic. For example, if you don't know the number of notebooks to process, or you want to choose the number of notebooks at run time, you can use a loop to iterate through the list of notebooks.

You can also use a loop to iterate through the output of a node or through elements in a data array.

### Loops in parallel

Add a parallel looping construct to the pipeline. A parallel loop runs the iterating nodes independently and possibly simultaneously.

For example, to train a machine learning model with a set of hyperparameters to find the best performer, you can use a loop to iterate over a list of hyperparameters to train the notebook variations in parallel. The results can be compared later in the flow to find the best notebook. {%- if site.prodkey == "icpd" %} To see limits on the number of loops you can run simultaneously, see [Limitations](../getting-started/known-issues-pipelines.html).{% endif %}{%- if site.prodkey == "cloud" %} To see limits on the number of loops you can run simultaneously, see [Limitations](../getting-started/known-issues.html#pipeline-issues).{% endif %}

{% if site.prodkey=="cloud" or site.prodkey == "icpd" %}
In the following example, a **Run Bash script** node searches for and retrieves notebooks that match specified criteria. A **Run DataStage job** node retrieves data from a Git repository. When input from each node is available, the loop process begins, running each notebook retrieved by the search and processing the data retrieved from the Git repository.

![Example of parallel loop](images/pipeline-config-3a.png){: height="50%" width="50%"}

Click **Expand to add nodes** or the outgoing icon on the node to view the full loop process. As the notebooks run, any errors in the notebook are captured in a condition called **Poor quality**. The condition triggers a Bash script to increment a user variable that is named **Increase error count**. When the value of the **Increase error count** variable meets the specified threshold, the loop is terminated.

![Example of parallel loop](images/pipeline-config-3b.png){: height="50%" width="50%"}

Since the flow is executed in parallel for each notebook, it returns results faster than a sequential loop.
{% endif %}

#### Input parameters when iterating List types

|Parameter|Description|
|---|---|
|List input| The *List input* parameter contains two fields, the data type of the list and the list content that the loop iterates over or a standard link to pipeline input or pipeline output.|
|Parallelism |Maximum number of tasks to be run simultaneously. Must be greater than zero|

#### Input parameters when iterating String types

|Parameter|Description|
|---|---|
|Text input| Text data that the loop reads from|
|Separator| A char used to split the text |
|Parallelism (optional)| Maximum number of tasks to be run simultaneously. Must be greater than zero|

If the input array element type is JSON or any type that is represented as such, this field might decompose it as dictionary. Keys are the original element keys and values are the aliases for output names.

### Loops in sequence

Add a sequential loop construct to the pipeline. Loops can iterate over a numeric range, a list, or text with a delimiter. 

A use case for sequential loops is if you want to try an operation 3 time before you determine whether an operation failed.

#### Input parameters

|Parameter|Description|
|---|---|
|List input| The *List input* parameter contains two fields, the data type of the list and the list content that the loop iterates over or a standard link to pipeline input or pipeline output.|
|Text input| Text data that the loop reads from. Specify a character to split the text.|
|Range| Specify the start, end, and optional step for a range to iterate over. The default step is 1.|

After you configure the loop iterative range, define a subpipeline flow inside the loop to run until the loop is complete. For example, it can invoke notebook, script, or other flow per iteration. 

### Terminate loop

In a parallel or sequential loop process flow, you can add a **Terminate pipeline** node to end the loop process anytime. You must customize the conditions for terminating.

{% render "note.html", type: "attention", text: "If you use the Terminate loop node, your loop cancels any ongoing tasks and terminates without completing its iteration." %}

### Loops
Configure a user variable with a key/value pair, then add the list of dynamic variables for this node.

For more information on how to create a user variable, see [Configuring global objects](ml-orchestration-flow-param.html).

#### Input parameters
x
|Parameter|Description|
|---|---|
|Name| Enter the name, or key, for the variable|
|Input type|Choose Expression or Pipeline parameter as the input type.
{: caption="Table 1. User variable input parameters" caption-side="top"}

- For expressions, use the built-in Expression Builder to create a variable that results from a custom expression.
- For pipeline parameters, assign a pipeline parameter and use the parameter value as input for the user variable.

### Set user variables
You can initiate and control the termination of a pipeline with a Terminate pipeline node from the Control category. When the error flow runs, you can optionally specify how to handle notebook or training jobs that were initiated by nodes in the pipeline. You must specify whether to wait for jobs to finish, cancel the jobs then stop the pipeline, or stop everything without canceling. Specify the options for the Terminate pipeline node.

#### Input parameters

|Parameter|Description|
|---|---|
|Terminator mode (optional)| Choose the behavior for the error flow|


Terminator mode can be:

- **Terminate pipeline run and all running jobs** stops all jobs and stops the pipeline.
- **Cancel all running jobs then terminate pipeline** cancels any running jobs before stopping the pipeline.
- **Terminate pipeline run after running jobs finish** waits for running jobs to finish, then stops the pipeline.
- **Terminate pipeline that is run without stopping jobs** stops the pipeline but allows running jobs to continue.

### Terminate pipeline
## Update nodes
{: #update}

Use update nodes to replace or update assets to improve performance. For example, if you want to standardize your tags, you can update to replace a tag with a new tag.

Update the training details for an [AutoAI experiment](autoai-overview.html).

#### Input parameters

|Parameter|Description|
|---|---|
|AutoAI experiment|Path to a project or a space, where the experiment resides|
|AutoAI experiment name (optional)| Name of the experiment to be updated, with optional description and tags|
|AutoAI experiment description (optional)|Description of the experiment|
|AutoAI experiment tags (optional)|Tags to identify the experiment|

#### Output parameters

|Parameter|Description|
|---|---|
|AutoAI experiment|Path of the updated experiment|

### Update AutoAI experiment
Use these parameters to update a batch deployment.

#### Input parameters

|Parameter|Description|
|---|---|
|Deployment| Path to the deployment to be updated|
|New name for the deployment (optional)|Name or ID of the deployment to be updated |
|New description for the deployment (optional)|Description of the deployment|
|New tags for the deployment (optional)| Tags to identify the deployment|
|ML asset|Name or ID of the machine learning asset to deploy|
|Hardware specification|Update the hardware specification for the job|

#### Output parameters

|Parameter|Description|
|---|---|
|Deployment|Path of the updated deployment|

### Update batch deployment
Update the details for a space.

#### Input parameters

{% if site.prodkey == "cloud" or site.prodkey == "wx" %}
|Parameter|Description|
|---|---|
|Space|Path of the existing space|
|Space name (optional)|Update the space name|
|Space description (optional)|Description of the space|
|Space tags (optional)|Tags to identify the space|
|WML Instance (optional)| Specify a new Machine Learning instance|
|WML instance| Specify a new Machine Learning instance. **Note:** Even if you assign a different name for an instance in the UI, the system name is **Machine Learning instance**. Differentiate between different instances by using the instance CRN|


{% else %}

|Parameter|Description|
|---|---|
|Space|Path of the existing space|
|Space name (optional)|Update the space name|
|Space description (optional)|Description of the space|
|Space tags (optional)|Optional append new tags or overwrite existing tags to identify the space|

{% endif %}

#### Output parameters

|Parameter|Description|
|---|---|
|Space|Path of the updated space|

### Update deployment space
Use these parameters to update an online deployment (web service).

#### Input parameters

|Parameter|Description|
|---|---|
|Deployment|Path of the existing deployment|
|Deployment name (optional)|Update the deployment name|
|Deployment description (optional)|Description of the deployment|
|Deployment tags (optional)|Tags to identify the deployment|
|Asset (optional)|Machine learning asset (or version) to be redeployed|

#### Output parameters

|Parameter|Description|
|---|---|
|Deployment|Path of the updated deployment|

### Update online deployment
{% comment %}
Update R-Shiny Deployment (in-progress)

This node updates an R-Shiny application deployment
Inputs

    id (Deployment) - ID of the deployment to be updated
    space-id (Space) - ID of the deployment space
    name (String) - Name of the new deployment
    description (String, optional) - Description of the new deployment
    asset (RShinyVersion) - RShiny asset version to be deployed
    hardware-spec (HardwareSpecVersion) - the hardware specification asset version
    authentication (String, enum) - anyone_with_url, any_valid_cpd_user, members_of_deployment_space
    tags (List[String], optional) - deployment tags
{% endcomment %}

## Delete nodes
{: #delete}

Configure parameters for delete operations. 

You can delete:

- AutoAI experiment
- Batch deployment
- Deployment space
- Online deployment

For each item, choose the asset for deletion.

### Delete
## Run nodes
{: #run}

Use these nodes to train an experiment, execute a script, or run a data flow.

Trains and stores [AutoAI experiment](autoai-overview.html) pipelines and models.

#### Input parameters

|Parameter|Description|
|---|---|
|AutoAI experiment|Browse for the ML Pipeline asset or get the experiment from a pipeline parameter or the output from a previous node.  |
|Training data asset|Browse or search for the data to train the experiment. Note that you can supply data at runtime by using a pipeline parameter|
|Holdout data asset (optional)|Optionally choose a separate file to use for holdout data for testingmodel performance|
|Models count (optional)| Specify how many models to save from best performing pipelines. The limit is 3 models|
|Run name (optional)|Name of the experiment and optional description and tags|
|Model name prefix (optional)| Prefix used to name trained models. Defaults to <(experiment name)> |
|Run description (optional)| Description of the new training run|
|Run tags (optional)| Tags for new training run|
|Creation mode (optional)| Choose how to handle a case where the pipeline flow tries to create an asset and one of the same name exists. One of: `ignore`, `fail`, `overwrite`|
|Error policy (optional)| Optionally, override the default error policy for the node|

#### Output parameters

|Parameter|Description|
|---|---|
|Models | List of paths of highest *N* trained and persisted model (ordered by selected evaluation metric)|
|Best model | path of the winning model (based on selected evaluation metric)|
|Model metrics | a list of trained model metrics (each item is a nested object with metrics like: holdout_accuracy, holdout_average_precision, ...)|
|Winning model metric |elected evaluation metric of the winning model|
|Optimized metric| Metric used to tune the model|
|Execution status| Information on the state of the job: pending, starting, running, completed, canceled, or failed with errors|
|Status message|Information about the state of the job|

### Run AutoAI experiment
Run an inline Bash script to automate a function or process for the pipeline. You can enter the Bash script code manually, or you can import the bash script from a resource, pipeline parameter, or the output of another node.

You can also use a Bash script to process large output files. For example, you can generate a large, comma-separated list that you can then iterate over using a loop.

In the following example, the user entered the inline script code manually. The script uses the `cpdctl` tool to search all notebooks with a set variable tag and aggregates the results in a JSON list. The list can then be used in another node, such as running the notebooks returned from the search.

![Example of a bash script node](images/pipeline-config-4.png){: height="50%" width="50%"}

#### Input parameters

|Parameter|Description|
|---|---|
|Inline script code|Enter a Bash script in the inline code editor. *Optional:* Alternatively, you can select a resource, assign a pipeline parameter, or select from another node. |
|Environment variables (optional)| Specify a variable name (the key) and a data type and add to the list of variables to use in the script.{%- if site.prodkey == "icpd" or site.prodkey == "opx" %}{% render "note.html", type: "attention", text: "For encrypted environment variables, their value is supplied as a mounted temporary file so it can be read without passing it externally. See <a href=\"ml-orchestration-flow-param.html#encrypt\">Encrypted parameters</a> for details." %}{%- endif %}|
|Runtime type (optional)| Select either use standalone runtime (default) or a shared runtime. Use a shared runtime for tasks that require running in shared pods. |
|Error policy (optional)| Optionally, override the default error policy for the node|


#### Output parameters

|Parameter|Description|
|---|---|
|Output variables |Configure a key/value pair for each custom variable, then click the Add button to populate the list of dynamic variables for the node|
|Return value|Return value from the node|
|Standard output|Standard output from the script|
|Standard error {% render "tag.html", title: "4.8.4 and later" %} | Standard error message from the script|
|Execution status|Information on the state of the job: pending, starting, running, completed, canceled, or failed with errors|
|Status message| Message associated with the status|

#### Rules for Bash script output

The output for a Bash script is often the result of a computed expression and can be large. When you are reviewing the properties for a script with valid large output, you can preview or download the output in a viewer.

These rules govern what type of large output is valid.

- The output of a `list_expression` is a calculated expression, so it is valid a large output.
- String output is treated as a literal value rather than a calculated expression, so it must follow the size limits that govern inline expressions. For example, you are warned when a literal value exceeds 1 KB and values of 2 KB and higher result in an error.
- {% render "tag.html", title: "4.8.4 and later" %} You can save standard error (`standard_error`) messages as a separate output and use it as input for other nodes or use it to conditionalize executing the next node.

#### Referencing a variable in a Bash script
{: #refvar}

The way  that you reference a variable in a script depends on whether the variable was created as an input variable or as an output variable. Output variables are created as a file and require a file path in the reference. Specifically:

- Input variables are available using the assigned name
- Output variable names require that `_PATH` be appended to the variable name to indicate that values have to be written to the output file pointed by the `{output_name}_PATH` variable.

#### Using SSH in Bash scripts
</br>

The following steps describe how to use `ssh` to run your remote Bash script.

1. Create a private key and public key.</br>
    ```bash
    ssh-keygen -t rsa -C "XXX"
    ```
    {: .codeblock}

2. Copy the public key to the remote host.</br>
    ```bash
    ssh-copy-id USER@REMOTE_HOST
    ```
    {: .codeblock}

3. On the remote host, check whether the public key contents are added into `/root/.ssh/authorized_keys`.</br>
4. Copy the public and private keys to a new directory in the **Run Bash script** node.
    ```bash
    mkdir -p $HOME/.ssh

    #copy private key content
    echo "-----BEGIN OPENSSH PRIVATE KEY-----
    ... ...
    -----END OPENSSH PRIVATE KEY-----" > $HOME/.ssh/id_rsa

    #copy public key content
    echo "ssh-rsa ...... " > $HOME/.ssh/id_rsa.pub

    chmod 400 $HOME/.ssh/id_rsa.pub
    chmod 400 $HOME/.ssh/id_rsa

    ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null -o GlobalKnownHostsFile=/dev/null -i $HOME/.ssh/id_rsa USER@REMOTE_HOST "cd /opt/scripts; ls -l; sh 1.sh"
    ```
    {: .codeblock}

#### Using SSH utilities in Bash scripts
</br>

The following steps describe how to use `sshpass` to run your remote Bash script.

1. Put your SSH password file in your system path, such as the mounted storage volume path.
2. Use the SSH password directly in the **Run Bash script** node:
    ```bash
    cd /mnts/orchestration
    ls -l sshpass
    chmod 777 sshpass
    ./sshpass -p PASSWORD ssh -o StrictHostKeyChecking=no USER@REMOTE_HOST "cd /opt/scripts; ls -l; sh 1.sh"
    ```
    {: .codeblock}

### Run Bash script
Configure this node to run selected deployment jobs.

#### Input parameters

|Parameter|Description|
|---|---|
|Deployment|Browse or search for the deployment job |
|Input data assets|Specify the data used for the batch job <br> {% render "note.html", type: "restriction", text: "Input for batch deployment jobs is limited to data assets. Deployments that require JSON input or multiple files as input, are not supported. For example, SPSS models and Decision Optimization solutions that require multiple files as input are not supported." %}|
|Output asset|Name of the output file for the results of the batch job. You can either select *Filename* and enter a custom file name, or *Data asset* and select an existing asset in a space.|
|Hardware specification (optional)|Browse for a hardware specification to apply for the job|
|Error policy (optional)| Optionally, override the default error policy for the node|

#### Output parameters

|Parameter|Description|
|---|---|
|Job|Path to the file with results from the deployment job|
|Job run|ID for the job|
|Execution status|Information on the state of the job: pending, starting, running, completed, canceled, or failed with errors|
|Status message| Information about the state of the job|

### Run batch deployment
{% if site.prodkey == "icpd" %}
[IBM DataStage](../../dstage/dsnav/topics/datastage.html) is a data integration tool for designing, developing, and running jobs that move and transform data. You can orchestrate different DataStage jobs by building a dependency graph between them. For more information on how to build a DataStage pipeline, see [Orchestrating flows with {{ site.data.keyword.pipeline_short }}](../../dstage/dsnav/topics/orchestrating-flows.html).
{% endif %}

{% if site.prodkey=="cloud" %}
IBM DataStage is a data integration tool for designing, developing, and running jobs that move and transform data. Run a DataStage job and use the output in a later node.
{% endif %}

{% if site.prodkey=="cloud" or site.prodkey == "icpd" %}
For example, the following flow shows a **Run DataStage** node that retrieves data from a Git repository. If the job completes successfully, the pipeline executes the next node and creates a deployment space. If the job fails, a notification email is triggered, and the loop is terminated.

![Running a DataStage job in a pipeline](images/pipeline-config-2.png){: height="50%" width="50%"}

|Parameter|Description|
|---|---|
|DataStage job|Path to the DataStage job |
|Values for local parameters (optional) | Edit the default job parameters. This option is available only if you have local parameters in the job. |
|Values from parameter sets (optional) |Edit the parameter sets used by this job. You can choose to use the parameters as defined by default, or use value sets from other pipelines' parameters. |
|Environment| Find and select the environment that is used to run the DataStage job. {% render "note.html", type: "attention", text: "Leave the environments field as is to use the default DataStage XS runtime. If you choose to override, specify an alternate environment for running the job. Be sure any environment that you specify is compatible with the hardware configuration to avoid a runtime error." %}|
|Environment variables (optional)| Specify a variable name (the key) and a data type and add to the list of variables to use in the job|
|Job parameters (optional)| Additional parameter to pass to the job when it runs. Specify a key/value pair and add to the list. {% render "note.html", type: "note", text: "If the local parameter \`DSJobInvocationId\` is used, that value is passed as the job name in the job details dashboard." %}|
|Error policy (optional)| Optionally, override the default error policy for the node|

#### Output parameters

|Parameter|Description|
|---|---|
|Job |Path to the results from the DataStage job|
|Job run| Information about the job run|
|Job name |Name of the job |
|Execution status|Information on the state of the job: pending, starting, running, completed, canceled, or failed with errors|
|Status message|Information about the state of the job|
{% endif %}

### Run DataStage job
{% if site.prodkey == "icpd" or site.prodkey == "opx" %}

Run Python or R code from a compressed package as a job. For more information, see [Code packages](code-package-spaces.html).

{% render "note.html", type: "note", text: "You can select code package jobs only from deployment spaces or from Git-based projects." %}

#### Input parameters

|Parameter|Description|
|---|---|
|Code package job|Select or enter a path to an existing code package job.|
|Environment (optional)| Select the space to run the code package job in, and assign environment resources. {% render "note.html", type: "attention", text: "Leave the environments field as is to use the default runtime. If you choose to override, specify an alternate environment for running the job. Be sure any environment that you specify is compatible with the code package language and hardware configuration to avoid a runtime error." %}|
|Environment variables (optional)| Specify a variable name (the key) and a data type and add to the list of variables to use in the script.|
|Error policy (optional)| Optionally, override the default error policy for the node|

#### Output parameters

|Parameter|Description|
|---|---|
|Job |Path to the results from the code package job|
|Job run| Information about the job run|
|Job name |Name of the job |
|Output variables |Configure a key/value pair for each custom variable, then click **Add** to populate the list of dynamic variables for the node|
|Execution status|Information on the state of the job: pending, starting, running, completed, canceled, or failed with errors|
|Status message|Information about the state of the job|

### Run code package job
{% endif %}

This node runs a specified Data Refinery job.

#### Input parameters

|Parameter|Description|
|---|---|
|Data Refinery job |Path to the Data Refinery job.|
|Environment | Path of the environment used to run the job {% render "note.html", type: "attention", text: "Leave the environments field as is to use the default runtime. If you choose to override, specify an alternate environment for running the job. Be sure any environment that you specify is compatible with the component language and hardware configuration to avoid a runtime error." %}|
|Error policy (optional)| Optionally, override the default error policy for the node|

#### Output parameters

|Parameter|Description|
|---|---|
|Job |Path to the results from the Data Refinery job|
|Job run|Information about the job run|
|Job name |Name of the job |
|Execution status|Information on the state of the flow: pending, starting, running, completed, canceled, or failed with errors|
|Status message| Information about the state of the flow|

### Run Data Refinery job
Use these configuration options to specify how to run a Jupyter Notebook in a pipeline.

#### Input parameters

|Parameter|Description|
|---|---|
|Notebook job|Path to the notebook job. |
|Environment |Path of the environment used to run the notebook. {% render "note.html", type: "attention", text: "Leave the environments field as is to use the default environment. If you choose to override, specify an alternate environment for running the job. Be sure any environment that you specify is compatible with the notebook language and hardware configuration to avoid a runtime error." %}|
|Environment variables (optional)|List of environment variables used to run the notebook job|
|Error policy (optional)| Optionally, override the default error policy for the node|

**Notes:**
- Environment variables that you define in a pipeline cannot be used for notebook jobs you run outside of {{ site.data.keyword.pipeline_short }}.
- You can run a notebook from a code package in a regular package.

#### Output parameters

|Parameter|Description|
|---|---|
|Job |Path to the results from the notebook job|
|Job run|Information about the job run|
|Job name |Name of the job |
|Output variables |Configure a key/value pair for each custom variable, then click **Add** to populate the list of dynamic variables for the node|
|Execution status|Information on the state of the run: pending, starting, running, completed, canceled, or failed with errors|
|Status message|Information about the state of the notebook run|

### Run notebook job
Run a reusable pipeline component that is created by using a Python script. For more information, see [Creating a custom component](ml-orchestration-custom-comp.html).

- If a pipeline component is available, configuring the node presents a list of available components.
- The component that you choose specifies the input and output for the node.
- Once you assign a component to a node, you cannot delete or change the component. You must delete the node and create a new one.

### Run Pipelines component
Add a pipeline to run a nested pipeline job as part of a containing pipeline. This is a way of adding reusable processes to multiple pipelines. You can use the output from a nested pipeline that is run as input for a node in the containing pipeline.

#### Input parameters

|Parameter|Description|
|---|---|
|{{ site.data.keyword.pipeline }} job|Select or enter a path to an existing {{ site.data.keyword.pipeline }} job.|
|Environment (optional)| Select the environment to run the {{ site.data.keyword.pipeline }} job in, and assign environment resources. {% render "note.html", type: "attention", text: "Leave the environments field as is to use the default runtime. If you choose to override, specify an alternate environment for running the job. Be sure any environment that you specify is compatible with the component language and hardware configuration to avoid a runtime error." %}|
|Job Run Name (optional) |A default job run name is used unless you override it by specifying a custom job run name. You can see the job run name in the **Job Details** dashboard.|
|Values for local parameters (optional) | Edit the default job parameters. This option is available only if you have local parameters in the job. |
|Values from parameter sets (optional) |Edit the parameter sets used by this job. You can choose to use the parameters as defined by default, or use value sets from other pipelines' parameters. |
|Error policy (optional)| Optionally, override the default error policy for the node|

#### Output parameters

|Parameter|Description|
|---|---|
|Job |Path to the results from the pipeline job|
|Job run|Information about the job run|
|Job name |Name of the job |
|Execution status| Returns a value of: Completed, Completed with warnings, Completed with errors, Failed, or Canceled|
|Status message| Message associated with the status|

#### Notes for running nested pipeline jobs

If you create a pipeline with nested pipelines and run a pipeline job from the top-level, the pipelines are named and saved as project assets that use this convention:

- The top-level pipeline job is named "Trial job - *pipeline guid*".
- All subsequent jobs are named "pipeline_ *pipeline guid*".

### Run Pipelines job
{% if site.prodkey == "icpd" or site.prodkey == "opx" %}

Run a general script job of Python or R.

#### Input parameters

|Parameter|Description|
|---|---|
|Python / R Script job|Select or enter a path to an existing script job. |
|Environment (optional)| Select the space to run the code package job in, and assign environment resources. |
|Environment variables (optional)| Specify a variable name (the key) and a data type and add to the list of variables to use in the script.|
|Error policy (optional)| Optionally, override the default error policy for the node|

#### Output parameters

|Parameter|Description|
|---|---|
|Job |Path to the results from the script job|
|Job run| Information about the job run|
|Job name |Name of the job |
|Output variables |Configure a key/value pair for each custom variable, then click **Add** to populate the list of dynamic variables for the node|
|Execution status|Information on the state of the job: pending, starting, running, completed, canceled, or failed with errors|
|Status message|Information about the state of the job|

{% render "accordion.html" id:"run-script" title: "Run script job" content: accordion-run-script %}
{% endif %}

Use these configuration options to specify how to run an {{ site.data.keyword.spss_modeler }} in a pipeline.

#### Input parameters

|Parameter|Description|
|---|---|
|{{ site.data.keyword.spss_modeler }} job|Select or enter a path to an existing {{ site.data.keyword.spss_modeler }} job.|
|Environment (optional)| Select the environment to run the {{ site.data.keyword.spss_modeler }} job in, and assign environment resources. {% render "note.html", type: "attention", text: "Leave the environments field as is to use the default SPSS Modeler runtime. If you choose to override, specify an alternate environment for running the job. Be sure any environment that you specify is compatible with the hardware configuration to avoid a runtime error." %}|
|Values for local parameters | Edit the default job parameters. This option is available only if you have local parameters in the job. |
|Error policy (optional)| Optionally, override the default error policy for the node|

#### Output parameters

|Parameter|Description|
|---|---|
|Job |Path to the results from the pipeline job|
|Job run|Information about the job run|
|Job name |Name of the job |
|Execution status| Returns a value of: Completed, Completed with warnings, Completed with errors, Failed, or Canceled|
|Status message| Message associated with the status|

### Run SPSS Modeler job

## Learn more

**Parent topic:** [Creating a pipeline](ml-orchestration-create.html)


{% comment %}

## Configure
{: #configure}

Configure Deployment in OpenScale (in-progress)

Use this node to add subscriptions in OpenScale

### Input parameters

|Parameter|Description|
|---|---|
|name (String)|Name of the new subscription|
|description (String, optional) |Description of the new subscription|
|space-id (Space)|ID of the deployment space|
|deployment-id (Deployment)| Id of the deployment|
|configuration (Dict)|a JSON with OpenScale monitor configurations|


### Output parameters

|Parameter|Description|
|---|---|
|subscription-id (Subscription)|ID of the newly created subscription|


## Find
{: #find}

Use this node to find assets.

### FindSpace

Find a deployment space.

#### Input parameters

|Parameter|Description|
|---|---|
|name (String)|Name of the space|
|tags (List[String])|Space tags (comma separated)|


#### Output parameters

|Parameter|Description|
|---|---|
|space|Path of the space|


### FindProject

Find a project for your pipeline.

#### Input parameters

|Parameter|Description|
|---|---|
|name (String)|Name of the project|
|tags (List[String])|Project tags (comma separated)|


#### Output parameters

|Parameter|Description|
|---|---|
|project | Path of the project|


### FindCatalog

Find a catalog for your pipeline.

#### Input parameters

|Parameter|Description|
|---|---|
|name (String)|Name of the catalog|
|tags (List[String])|Catalog tags (comma separated)|


#### Output parameters

|Parameter|Description|
|---|---|
|catalog|Path of the catalog|


{% endcomment %}
